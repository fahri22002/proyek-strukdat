#pragma once;
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
    int jumlahbarang;
    barang unit;
    kurir kur;
    int prior;
};
struct riwayat{
    antar data;
    riwayat *next;
    riwayat *prev;
};