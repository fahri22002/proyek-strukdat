#include <iostream>
#include <ctime>
#include <iomanip>
#include "stack.hpp"
#include "queue.hpp"
#include "manage.hpp"


int main(){
    stack topRiwayat;
    topRiwayat = createstack();
    char hidup = 'y';
    while (hidup == 'y'){
        std::cout<<"Pilih :\n1. Tampilkan data\n2. Input data\n3. Edit data antar";
        std::cout<<"\n4. Undo\n5. Redo\n6. Tampilkan riwayat barang sampai\n7. Edit data barang\n8. Edit data kurir\n";
        int ch;
        std::cin>>ch;
        if (ch == 1){
            showRiwayat(topRiwayat);
        } else if (ch == 2){
            push(topRiwayat, createRiwayat(input()));
        } else if (ch == 3){

        } else if (ch == 4){

        } else if (ch == 5){

        } else if (ch == 6){

        } else {

        }
        std::cout<<"Action (y/n)\n";
        std::cin>>hidup;
    }
    return 0;
}