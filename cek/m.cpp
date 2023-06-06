//main
#include <iostream>
#include <iomanip>
#include "n.hpp"
#include "f.hpp"
#include "s.hpp"
#include "q.hpp"


void printSeparatorLine() {
    std::cout << "-------------------------------------------\n";
}
void printHeader(const std::string& text) {
    std::cout << "=== " << text << " ===\n";
}
int main(){
    list firstList, lastList, selesaiF, selesaiL;
    list cache;
    stack topUndo = createStack();
    stack topRedo = createStack();
    createList(firstList, lastList);
    createList(selesaiF, selesaiL);
    char hidup = 'y';
    while (hidup != 'n'){
        printSeparatorLine();
        if (!isStackEmpty(topUndo)){
            std::cout<<"<UNDO|";
        } else {
            std::cout<<"      ";
        }
        if (!isStackEmpty(topRedo)){
            std::cout<<"|REDO>\n";
        } else {
            std::cout<<"\n";
        }
        printHeader("MENU");
        std::cout<<"Pilih :\n1. Tampilkan data\n2. Input data antar\n3. Hapus data antar";
        std::cout<<"\n4. Edit Antar\n5. Undo\n6. Redo\n7. Selesai";
        std::cout<<"\n8. Tampilkan History Sampai\n";
        int ch;
        printSeparatorLine();
        std::cout << "Pilihan : ";
        std::cin>>ch;
        printSeparatorLine();
        std::cout << "\n";
        if (ch == 1){
            printHeader("DATA ANTAR");
            showRiwayat(firstList);
        } else if (ch == 2){
            printHeader("INPUT DATA ANTAR");
            addList(firstList, lastList, createRiwayat(input()), topUndo, 2);
            delRedo(topRedo);
        } else if (ch == 3){
            printHeader("HAPUS DATA ANTAR");
            int idantar, letak=1;
            std::cout << "ID Antar : ";
            std::cin>>idantar;
            std::cin.ignore();
            if (!isThere(firstList, idantar)){
                std::cout<<"ID antar tidak ditemukan\n";
            }
            deleteAntar(firstList, lastList, topUndo, idantar, 3);
            delRedo(topRedo);
        } else if (ch == 4){
            printHeader("EDIT DATA ANTAR");
            int idantar;
            std::cout<<"Masukkan ID antar yang akan diedit :";
            std::cin>>idantar; std::cin.ignore();
            if (isThere(firstList, idantar) != nullptr){
                editAntar(firstList, lastList, topUndo, createRiwayat(inputEdit(isThere(firstList, idantar))), idantar);
            } else {
                std::cout<<"ID antar tidak ditemukan\n";
            }
            delRedo(topRedo);
        } else if (ch == 5){
            if (!isStackEmpty(topUndo)){
                printHeader("UNDO BERHASIL");
                if (topUndo->opcode == 7) {
                    topUndo->opcode = 3;
                    undo(topUndo, topRedo, firstList,lastList);
                    topRedo->opcode = 7;
                    topUndo->opcode = 2;
                    undo(topUndo, topRedo, selesaiF, selesaiL);
                    topRedo->opcode = 7;
                } else {
                    undo(topUndo, topRedo, firstList,lastList);
                }
            } else {
                printHeader("UNDO GAGAL");
            }
        } else if (ch == 6){
            if (!isStackEmpty(topRedo)){
                printHeader("UNDO BERHASIL");
                if (topRedo->opcode == 7) {
                    topRedo->opcode = 2;
                    redo(topUndo, topRedo, selesaiF, selesaiL);
                    topUndo->opcode = 7;
                    topRedo->opcode = 3;
                    redo(topUndo, topRedo, firstList, lastList);
                    topUndo->opcode = 7;
                } else {
                    redo(topUndo, topRedo, firstList, lastList);
                }
            } else {
                printHeader("REDO GAGAL");
            }
            
            
        } else if (ch == 7){
            if (firstList != nullptr){
                printHeader("PENGIRIMAN BARHASIL!");
                addList(selesaiF, selesaiL, createRiwayat(firstList->data), topUndo, 7);
                deleteAntar(firstList, lastList, topUndo, firstList->data.idantar, 7);
                delRedo(topRedo);
            } else {
                printHeader("TIDAK ADA BARANG YANG DIANTAR");
            }
        } else if (ch == 8) {
            printHeader("TAMPILKAN DATA PENGIRIMAN SELESAI");
            showRiwayat(selesaiF);
        }
        std::cout<<"\nAction (y/n) : ";
        std::cin>>hidup;
    }
    return 0;
}
