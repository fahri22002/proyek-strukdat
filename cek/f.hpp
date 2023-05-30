//fungsi
#pragma once
#include "n.hpp"
#include "s.hpp"
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
void showRiwayat(list first){
    int i = 1;
    if (first == nullptr){
        return;
    }
    while (first != nullptr){
        std::cout<<i<<"\n";//nanti buat tabel
        std::cout<<"id antar "<<first->data.idantar<<"\n";
        std::cout<<"prior "<<first->data.prior<<"\n";
        std::cout<<"nama kurir "<<first->data.kur.nama<<"\n";
        listBarang temp = first->data.unit;
        for (int i = 0; i<first->data.banyakBarang; i++){
            std::cout<<"id barang "<<temp->idBarang<<"\n";
            temp = temp->next;
        }
        first = first->next;
        i++;
    }
}