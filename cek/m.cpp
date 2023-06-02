//main
#include <iostream>
#include <iomanip>
#include "n.hpp"
#include "f.hpp"
#include "s.hpp"
#include "q.hpp"

int main(){
    list firstList, lastList, selesaiF, selesaiL;
    list cache;
    stack topUndo = createStack();
    stack topRedo = createStack();
    createList(firstList, lastList);
    createList(selesaiF, selesaiL);
    char hidup = 'y';
    while (hidup != 'n'){
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
        std::cout<<"Pilih :\n1. Tampilkan data\n2. Input data antar\n3. Hapus data antar";
        std::cout<<"\n4. Edit Antar\n5. Undo\n6. Redo\n7. Selesai";
        std::cout<<"\n8. Tampilkan History Sampai\n9. input data kurir\n";
        int ch;
        std::cout << "Pilihan : ";
        std::cin>>ch;
        std::cout << "\n";
        if (ch == 1){
            showRiwayat(firstList);
        } else if (ch == 2){
            addList(firstList, lastList, createRiwayat(input()), topUndo, 2);
            delRedo(topRedo);
        } else if (ch == 3){
            int idantar, letak=1;
            std::cout << "ID Antar : ";
            std::cin>>idantar;
            std::cin.ignore();
            deleteAntar(firstList, lastList, topUndo, idantar, 3);
            delRedo(topRedo);
        } else if (ch == 4){
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
            }
        } else if (ch == 6){
            if (!isStackEmpty(topRedo)){
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
            }
            
            
        } else if (ch == 7){
            addList(selesaiF, selesaiL, createRiwayat(firstList->data), topUndo, 7);
            deleteAntar(firstList, lastList, topUndo, firstList->data.idantar, 7);
            delRedo(topRedo);
        } else if (ch == 8) {
            showRiwayat(selesaiF);
        }
        std::cout<<"\nAction (y/n) : ";
        std::cin>>hidup;
    }
    return 0;
}
