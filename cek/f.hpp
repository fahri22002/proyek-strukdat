//fungsi
#pragma once
#include "n.hpp"
#include "s.hpp"
#include <iostream>
#include <cstring>

antar input(){
    antar send;
    kurir kur;

    std::cout<<"Masukkan banyak barang      : ";
    std::cin>>send.banyakBarang;
    listBarang unit;
    unit = createlistbarang();
    for (int i = 0; i<send.banyakBarang; i++){
        std::cout<<"Barang ke-"<<i+1<<"\n";
        pushBarang(unit, createnode());
    }
    send.unit = unit;
    
    std::cout<<"Masukkan id kurir           : ";
    std::cin>>kur.idkurir;
    std::cin.ignore();
    std::cout<<"Masukkan nama kurir         : ";
    getline(std::cin, kur.nama, '\n');
    
    std::cout<<"Masukkan id antar           : ";
    std::cin>>send.idantar;
    std::cout<<"Masukkan prioritas          : ";
    std::cin>>send.prior;
    std::cin.ignore();
    send.kur = kur;

    return send;
}
void showRiwayat(list first){
    int i = 1;
    if (first == nullptr){
        std::cout << "- Tidak ada data - \n"; 
        return;
    }
    while (first != nullptr){
        std::cout<<"Data " << i <<"\n";//nanti buat tabel
        std::cout<<"ID antar        : "<<first->data.idantar<<"\n";
        std::cout<<"Prioritas       : "<<first->data.prior<<"\n";
        std::cout<<"Nama Kurir      : "<<first->data.kur.nama<<"\n";
        std::cout<<"Nama pengirim   : "<<first->data.unit->namaPengirim<<"\n";
        std::cout<<"Alamat pengirim : "<<first->data.unit->alamatPengirim<<"\n";
        std::cout<<"No. Hp pengirim : "<<first->data.unit->noHp<<"\n";
        std::cout<<"Nama penerima   : "<<first->data.unit->namaPenerima<<"\n";
        std::cout<<"Alamat penerima : "<<first->data.unit->alamatPenerima<<"\n";
        listBarang temp = first->data.unit;
        for (int i = 0; i<first->data.banyakBarang; i++){
            std::cout<<"ID barang " << i+1 << "     : "<<temp->idBarang<<"\n";
            temp = temp->next;
        }
        first = first->next;
        i++;
    }
}
void deleteAntar(list &first, list &last, stack &topUndo, int idantar, int opcode){
    if (first == nullptr){
        return;
    }
    int letak=1;
    list temp = first;
    while(temp->data.idantar != idantar){
        temp = temp->next;
        letak++;
        if (temp == nullptr){
            std::cout<<"Tidak ditemukan\n";
            return;
        }
    }
    if (temp->prev == nullptr && temp->next == nullptr){
        pushCache (topUndo, createCache(temp, opcode, letak));
        last = nullptr;
        first = nullptr;
    } else if (temp->prev == nullptr){
        first = temp->next;
        temp->next = nullptr;
        first->prev = nullptr;
        pushCache (topUndo, createCache(temp, opcode, letak));
    } else if (temp->next == nullptr){
        last = temp->prev;
        temp->prev = nullptr;
        last->next = nullptr;
        pushCache (topUndo, createCache(temp, opcode, letak));
    } else {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->prev = nullptr;
        temp->next = nullptr;
        pushCache (topUndo, createCache(temp, opcode, letak));
    }
}
riwayatptr isThere (list first, int idantar){
    while (first != nullptr){
        if (first->data.idantar == idantar){
            return first;
        }
        first = first->next;
    }
    return nullptr;
}
antar inputEdit(riwayatptr edit){
    antar send;
    kurir kur;
    std::cout<<"id antar yang diedit : "<<edit->data.idantar<<"\n";
    std::cout<<"prioritas : "<<edit->data.idantar<<"\n";
    std::cout<<"Masukkan banyak barang      : ";
    std::cin>>send.banyakBarang;
    listBarang unit;
    unit = createlistbarang();
    for (int i = 0; i<send.banyakBarang; i++){
        std::cout<<"Barang ke-"<<i+1<<"\n";
        pushBarang(unit, createnode());
    }
    send.unit = unit;
    
    std::cout<<"Masukkan id kurir           : ";
    std::cin>>kur.idkurir;
    std::cin.ignore();
    std::cout<<"Masukkan nama kurir         : ";
    getline(std::cin, kur.nama, '\n');
    
    send.idantar = edit->data.idantar;
    send.prior = edit->data.prior;
    send.kur = kur;
    
    return send;
}
void editAntar (list &first, list &last, stack &topUndo, riwayatptr baru, int idantar){
    if (first->data.idantar == idantar){
        list change = first;
        baru->next = first->next;
        if (first->next != nullptr){
            first->next->prev = baru;
        } else {
            last = baru;
        }
        first->next = nullptr;
        first = baru;
        pushCache (topUndo, createCache (change, 4, 1));
    } else {
        list temp = first;
        int lokasi = 1;
        while (temp->data.idantar != idantar){
            temp = temp->next;
            lokasi++;
        }
        baru->next = temp->next;
        baru->prev = temp->prev;
        if (temp->next != nullptr){
            temp->next->prev = baru;
        } else {
            last = baru;
        }
        temp->prev->next = baru;
        temp->next = nullptr;
        temp->prev = nullptr;
        pushCache (topUndo, createCache (temp, 4, lokasi));
    }
}