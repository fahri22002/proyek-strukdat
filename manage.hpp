#pragma once
#include "stack.hpp"
#include <iostream>

antar input(){
    antar send;
    kurir kur;

    std::cout<<"masukkan banyak barang\n";
    std::cin>>send.banyakBarang;
    barang unit[send.banyakBarang];
    for (int i = 0; i<send.banyakBarang; i++){
        std::cout<<"barang ke-"<<i<<"\n";
        std::cout<<"masukkan id unit (5 char)\n";
        std::cin>>unit[i].idBarang;
        std::cin.ignore();
        std::cout<<"masukkan nama pengirim\n";
        getline(std::cin, unit[i].namaPengirim, '\n');
        std::cout<<"masukkan alamat pengirim\n";
        getline(std::cin, unit[i].alamatPengirim, '\n');
        std::cout<<"masukkan noHP pengirim\n";
        std::cin>>unit[i].noHp;
        std::cin.ignore();
        std::cout<<"masukkan nama penerima\n";
        getline(std::cin, unit[i].namaPenerima, '\n');
        std::cout<<"masukkan alamat penerima\n";
        getline(std::cin, unit[i].alamatPenerima, '\n');
        send.unit[i] = unit[i];
    }
    
    
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
    while (top != nullptr){
        std::cout<<i<<"\n";//nanti buat tabel
        std::cout<<top->data.idantar<<"\n";
        std::cout<<top->data.prior<<"\n";
        std::cout<<top->data.kur.nama<<"\n";
        for (int i = 0; i<top->data.banyakBarang; i++){
            std::cout<<top->data.unit[i].alamatPenerima<<"\n";
        }
        top = top->next;
        i++;
    }
}