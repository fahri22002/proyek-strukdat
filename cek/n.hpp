//node
#pragma once
#include <iostream>

struct barang{
    int idBarang;
    std::string namaPengirim;
    std::string alamatPengirim;
    std::string namaPenerima;
    std::string alamatPenerima;
    char noHp[12];
    barang *next;
    barang *prev;
};
struct kurir{
    int idkurir;
    std::string nama;

};
typedef barang *ptrBarang;
using listBarang = ptrBarang;
listBarang createlistbarang(){
    return nullptr;
}
ptrBarang createnode(){
    ptrBarang unit = new barang;
    std::cout<<"masukkan id unit (5 char)\n";
    std::cin>>unit->idBarang;
    std::cin.ignore();
    std::cout<<"masukkan nama pengirim\n";
    getline(std::cin, unit->namaPengirim, '\n');
    std::cout<<"masukkan alamat pengirim\n";
    getline(std::cin, unit->alamatPengirim, '\n');
    std::cout<<"masukkan noHP pengirim\n";
    std::cin>>unit->noHp;
    std::cin.ignore();
    std::cout<<"masukkan nama penerima\n";
    getline(std::cin, unit->namaPenerima, '\n');
    std::cout<<"masukkan alamat penerima\n";
    getline(std::cin, unit->alamatPenerima, '\n');
    unit->next = nullptr;
    unit->prev = nullptr;
    return unit;
}
bool isUnitEmpty(listBarang top){
    return (top == nullptr)? true:false;
}
void pushBarang(listBarang &top, ptrBarang baru){
    if (isUnitEmpty(top)){
        top = baru;
    } else {
        baru->next = top;
        top->prev = baru;
        top = baru;
    }
}
