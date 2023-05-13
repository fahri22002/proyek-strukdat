#pragma once
#include "stack.hpp"
#include <iostream>

antar input(){
    barang unit;
    std::cout<<"masukkan id unit (5 char)\n";
    std::cin>>unit.idBarang;
    std::cin.ignore();
    std::cout<<"masukkan nama pengirim\n";
    getline(std::cin, unit.namaPengirim, '\n');
    std::cout<<"masukkan alamat pengirim\n";
    getline(std::cin, unit.alamatPengirim, '\n');
    std::cout<<"masukkan noHP pengirim\n";
    std::cin>>unit.noHp;
    std::cin.ignore();
    std::cout<<"masukkan nama penerima\n";
    getline(std::cin, unit.namaPenerima, '\n');
    std::cout<<"masukkan alamat penerima\n";
    getline(std::cin, unit.alamatPenerima, '\n');
    kurir kur;
    std::cout<<"masukkan id kurir 6 char\n";
    std::cin>>kur.idkurir;
    std::cin.ignore();
    std::cout<<"masukkan nama kurir\n";
    getline(std::cin, kur.nama, '\n');
    antar send;
    std::cout<<"masukkan id antar 7 char\n";
    std::cin>>send.idantar;
    std::cout<<"masukkan prioritas\n";
    std::cin>>send.prior;
    std::cin.ignore();
    send.unit = unit;
    send.kur = kur;
    return send;
}
void showRiwayat(stack top){
    int i = 1;
    while (top != nullptr){
        std::cout<<i<<"\n";
        std::cout<<top->data.idantar<<"\n";
        std::cout<<top->data.prior<<"\n";
        std::cout<<top->data.kur.nama<<"\n";
        std::cout<<top->data.unit.alamatPenerima<<"\n";
        top = top->next;
        i++;
    }
}