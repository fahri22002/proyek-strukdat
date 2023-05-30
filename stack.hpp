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
struct antar{
    int idantar;
    int banyakBarang;
    listBarang unit;
    kurir kur;
    int prior;
};
struct riwayat{
    antar data;
    riwayat *next;
    riwayat *prev;
};
typedef riwayat *riwayatptr;
using stack = riwayatptr;

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

stack createstack(){
    return nullptr;
}
riwayatptr createRiwayat(antar data){
    riwayatptr baru = new riwayat;
    baru->data = data;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}
bool isEmpty(stack top){
    return (top == nullptr)? true:false;
}
void push (stack &top, riwayatptr baru){
    if (isEmpty(top)){
        top = baru;
    } else {
        baru->next = top;
        top->prev = baru;
        top = baru;
    }
}
riwayatptr pop (stack& top, stack& topcache){
    riwayatptr temp;
    if (isEmpty(top)){
        return nullptr;
    } else if(top->next == nullptr){
        temp = top;
        top = nullptr;
    } else {
        temp = top;
        top = top->next;
        temp->next = nullptr;
        top->prev = nullptr;
    } 
    push (topcache, temp);
    return temp;
}
