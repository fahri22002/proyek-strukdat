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
        listBarang temp = top->data.unit;
        for (int i = 0; i<top->data.banyakBarang; i++){
            std::cout<<temp->idBarang<<"\n";
            temp = temp->next;
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
        switch (ch){
            case 1:
                std::cout<<"barang ke-"<<temp->data.banyakBarang+1<<"\n";
                temp->data.banyakBarang++;
                pushBarang(temp->data.unit, createnode());
                break;
            case 2:
                temp->data.banyakBarang--;
                break;//edit barangnya di pop
            case 3:
                //test
                break;
        }
        std::cout<<"id kurir 6 char = "<<temp->data.kur.idkurir<<"\n";
        std::cout<<"edit menjadi:"; std::cin>>temp->data.kur.idkurir;
        std::cin.ignore();
        std::cout<<"nama kurir"<<temp->data.kur.nama<<"\n";
        std::cout<<"edit menjadi:";getline(std::cin, temp->data.kur.nama, '\n');
    }
    return top;
}