#pragma once
#include <iostream>

struct barang{
    char idBarang[5];
    std::string namaPengirim;
    std::string alamatPengirim;
    std::string namaPenerima;
    std::string alamatPenerima;
    char noHp[12];
};
struct kurir{
    char idkurir[6];
    std::string nama;

};
struct antar{
    char idantar[7];
    int banyakBarang;
    barang unit[10];
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