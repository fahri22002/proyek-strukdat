//main
#include <iostream>
#include <ctime>
#include <iomanip>
#include "n.hpp"
#include "f.hpp"
#include "s.hpp"
#include "q.hpp"


int main(){
    list firstList, lastList;
    list cache;
    stack topUndo = createStack();
    stack topRedo = createStack();
    createList(firstList, lastList);
    char hidup = 'y';
    while (hidup == 'y'){
        std::cout<<"Pilih :\n1. Tampilkan data\n2. Input data antar\n3. Hapus data antar";
        std::cout<<"\n4. Undo\n5. Redo\n6. Tampilkan riwayat barang sampai";
        std::cout<<"\n7. Edit data barang\n8. Edit data kurir\n9. input data kurir";
        int ch;
        std::cin>>ch;
        if (ch == 1){
            showRiwayat(firstList);
        } else if (ch == 2){
            addList(firstList, lastList, createRiwayat(input()), topUndo, ch);
            delRedo(topRedo);
        } else if (ch == 3){
            
        } else if (ch == 4){
            undo(topUndo, topRedo, firstList);
        } else if (ch == 5){
            redo(topUndo, topRedo, firstList, lastList);
        } else if (ch == 6){

        } else {

        }
        std::cout<<"Action (y/n)\n";
        std::cin>>hidup;
    }
    return 0;
}