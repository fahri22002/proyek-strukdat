#pragma once
#include "stack.hpp"

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

typedef riwayatkrm *queue;

void enqueue(const int& noRiwayat, const std::tm& waktu, char& idBarang, queue& head, queue& tail) {
    riwayatkrm* Node = new riwayatkrm;
    Node->noRiwayat = noRiwayat;
    Node->waktu = waktu;
    Node->idBarang = idBarang;
    Node->next = nullptr;

    if (head == nullptr) {
        head = tail = Node;
    } else {
        tail->next = Node;
        tail = Node;
    }
}

void dequeue(queue& head) {
    if (head == nullptr) {
        return; 
    }
  
    riwayatkrm* temp = head;
    head = head->next;
    delete temp;
}

void printRiwayat(queue head) {
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

