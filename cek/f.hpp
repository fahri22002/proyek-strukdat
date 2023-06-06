//fungsi
#pragma once
#include "n.hpp"
#include "s.hpp"
#include <iostream>
#include <iomanip>

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
void lineTable (bool i){
    if(i){
        std::cout<<"+----+----------+----------+----------+---------------+---------------+----------+---------------+---------------+---------------+---------------+---------------+\n";
    }
}
void awalTableBarang (){
    std::cout<<std::setw(5)<<"|"<<std::setw(11)<<"|"<<std::setw(11)<<"|"<<std::setw(11)<<"|"<<std::setw(16)<<"|"<<std::setw(16)<<"|"<<"|";
}
void showRiwayat(list first){
    int i = 1;
    if (first == nullptr){
        std::cout << "- Tidak ada data - \n"; 
        return;
    }
    lineTable(1);
    std::cout<<"|NO  |ID antar  |Prioritas |ID kurir  |Nama Kurir     |Banyak barang  |ID Barang |Nama Pengirim  |Alamat Pengirim|No. Hp Pengirim|Nama Penerima  |Alamat Penerima|\n";
    lineTable(1);
    while (first != nullptr){
        std::cout<<"|";
        std::cout<<std::setw(4) <<std::right<< i <<"|";//nanti buat tabel
        std::cout<<std::setw(10)<<std::left<<first->data.idantar <<"|";
        std::cout<<std::setw(10)<<std::left<<first->data.prior   <<"|";
        std::cout<<std::setw(10)<<std::left<<first->data.kur.idkurir<<"|";
        std::cout<<std::setw(15)<<std::left<<first->data.kur.nama<<"|";
        std::cout<<std::setw(15)<<std::left<<first->data.banyakBarang<<"|";
        listBarang temp = first->data.unit;
        for (int i = 0; i<first->data.banyakBarang; i++){
            if (i!=0){
                awalTableBarang();
            }
            std::cout<<std::setw(10)<<std::left<<temp->idBarang<<"|";
            std::cout<<std::setw(15)<<std::left<<temp->namaPengirim<<"|";
            std::cout<<std::setw(15)<<std::left<<temp->alamatPengirim<<"|";
            std::cout<<std::setw(15)<<std::left<<temp->noHp<<"|";
            std::cout<<std::setw(15)<<std::left<<temp->namaPenerima<<"|";
            std::cout<<std::setw(15)<<std::left<<temp->alamatPenerima<<"|\n";
            lineTable(i == first->data.banyakBarang -1);
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
    std::cout<<"prioritas : "<<edit->data.prior<<"\n";
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