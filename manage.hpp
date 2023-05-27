#pragma once
#include "stack.hpp"
#include <iostream>
#include <cstring>

antar input(){
    antar send;
    kurir kur;

    std::cout<<"masukkan banyak barang\n";
    std::cin>>send.banyakBarang;
    listBarang unit;
    unit = createlistbarang();
    for (int i = 0; i<send.banyakBarang; i++){
        std::cout<<"barang ke-"<<i+1<<"\n";
        pushBarang(unit, createnode());
    }
    send.unit = unit;
    
    std::cout<<"masukkan id kurir 6 char\n";
    std::cin>>kur.idkurir;
    std::cin.ignore();
    std::cout<<"masukkan nama kurir\n";
    getline(std::cin, kur.nama, '\n');
    
    std::cout<<"masukkan id antar 7 char\n";
    std::cin>>send.idantar;
    std::cout<<"masukkan prioritas\n";
    std::cin>>send.prior;
    std::cin.ignore();
    send.kur = kur;
    return send;
}
void showRiwayat(stack top){
    int i = 1;
    if (top == nullptr){
        return;
    }
    while (top != nullptr){
        std::cout<<i<<"\n";//nanti buat tabel
        std::cout<<top->data.idantar<<"\n";
        std::cout<<top->data.prior<<"\n";
        std::cout<<top->data.kur.nama<<"\n";
        listBarang temp = top->data.unit;
        for (int i = 0; i<top->data.banyakBarang; i++){
            std::cout<<temp->idBarang<<"\n";
            temp = temp->next;
        }
        top = top->next;
        i++;
    }
}

riwayat* searchData(stack top){
    int id;
    std::cin>>id;
    std::cin.ignore();
    riwayat *nullreturn = new riwayat;
    nullreturn->data.idantar=0;
    while (top->data.idantar != id ){
        if (top->next == nullptr){
            return nullreturn;
            break;
        }
        top=top->next;
    }
    return (top);
}

void deleteData(stack &top, riwayatptr search, stack& cache){
    stack del = top;
    while (del != search){
        del = del->next;
    } 
    if (del->next == nullptr && del->prev == nullptr){
        top=nullptr;
    } else if (del->next == nullptr){
        del->prev->next = nullptr;
        del->prev = nullptr;
        
    } else if (del->prev == nullptr){
        if(del == top){
            top = top->next;
        }
        del->next->prev = nullptr;
        del->next = nullptr;
        
    } else {
        del->next->prev = del->prev;
        del->prev->next = del->next;
        del->next = nullptr;
        del->prev = nullptr;
    }
    push(cache, del);
    delete del;

}