#pragma once
#include "stack.hpp"
#include <ctime>

struct antrian{
    antar data;
    antrian *next;
    antrian *prev;
}; // nanti buat riwayat barang terkirim

struct riwayatkrm {
    int noRiwayat;
    std::tm waktu;
    char idBarang;
    riwayatkrm* next;
};

typedef riwayatkrm *first;

void updRiwayat(const int& noRiwayat, const std::tm& waktu, char& idBarang, first& head) {
    riwayatkrm* Node = new riwayatkrm;
    Node->noRiwayat = noRiwayat;
    Node->waktu = waktu;
    Node->idBarang = idBarang;
    Node->next = nullptr;

    if (head == nullptr) {
        head = Node;
    } else {
        riwayatkrm* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = Node;
    }
}

void PrintRiwayat(first& head) {
    riwayatkrm* current = head;
    while (current != nullptr) {
        std::cout << "No : " << current->noRiwayat << std::endl;

        std::stringstream ss;
        ss << std::put_time(&current->waktu, "%Y-%m-%d %H:%M:%S");
        std::string waktuStr = ss.str();
        std::cout << "Waktu Pengiriman : " << waktuStr << std::endl;

        std::cout << "ID Barang : " << current->idBarang << std::endl;
        std::cout << "--------------------------" << std::endl;
        current = current->next;
    }
}


