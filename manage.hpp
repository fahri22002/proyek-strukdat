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

antar searchData(stack top, char edit[]){
    antar nullreturn;
    std::strcpy(nullreturn.idantar, "000000");
    while (top->data.idantar != edit ){
        if (top->next == nullptr){
            return nullreturn;
            break;
        }
        top=top->next;
    }
    return top->data;
}

stack edit(stack top, antar editData){
    stack temp = top;
    if (editData.idantar == "000000"){
        std::cout<<"tidak ditemukan!\n";
        return top;
    } else {
        while (temp->data.idantar != editData.idantar){
            temp = temp->next;
        }
        std::cout<<"idantar = "<<temp->data.idantar<<"\n";
        std::cout<<"edit menjadi : "; std::cin>>temp->data.idantar;
        std::cout<<"prioritas = "<<temp->data.prior<<"\n";
        std::cout<<"edit menjadi : "; std::cin>>temp->data.prior;
        std::cout<<"banyak barang = "<<temp->data.banyakBarang<<"\n";
        std::cout<<"ketik:\n1. tambah\n2. hapus\n3. tidak keduanya\n";
        int ch;
        int editn;
        std::cin>>ch;
        std::cin.ignore();
        barang unit;
        switch (ch){
            case 1:
                std::cout<<"barang ke-"<<temp->data.banyakBarang+1<<"\n";
                temp->data.banyakBarang++;
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
                temp->data.unit[temp->data.banyakBarang-1] = unit;
                break;
            case 2:
                temp->data.banyakBarang--;
                break;
            case 3:
                break;
        }
        std::cout<<"id kurir 6 char = "<<temp->data.kur.idkurir<<"\n";
        std::cout<<"edit menjadi:"; std::cin>>temp->data.kur.idkurir;
        std::cin.ignore();
        std::cout<<"nama kurir"<<temp->data.kur.nama<<"\n";
        std::cout<<"edit menjadi:";getline(std::cin, temp->data.kur.nama, '\n');
    }
}