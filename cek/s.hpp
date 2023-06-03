//stack
#pragma once
#include <iostream>

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
using list = riwayatptr;

struct cache{
    int opcode;
    riwayatptr data;
    int letak;
    cache *next;
};
typedef cache *ptrCache;
using stack = ptrCache;

ptrCache createCache (riwayatptr data, int opcode, int lokasi);
void pushCache (stack &top, ptrCache baru);

void createList(list &first, list&last){
    first = nullptr;
    last = nullptr;
}
riwayatptr createRiwayat(antar data){
    riwayatptr baru = new riwayat;
    baru->data = data;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}
int banyakList (list first){
    int lokasi = 1;
    first = first->next;
    while (first != nullptr){
        first = first->next;
        lokasi++;
    }
    return lokasi;
}
bool isEmpty(list top){
    return (top == nullptr)? true:false;
}
void addList (list &first, list &last, riwayatptr baru, stack &topUndo, int opcode){
    if (isEmpty(first)){
        first = baru;
        last = baru;
        pushCache (topUndo, createCache(baru, opcode, int(1)));
    } else {
        if(baru->data.prior <= last->data.prior){
            last->next = baru;
            baru->prev = last;
            last = baru;
            
            pushCache (topUndo, createCache(baru, opcode, banyakList(first)));
        } else {
            list temp = last;
            int lokasi = banyakList(first) + 1;
            while (baru->data.prior > temp->data.prior ){
                temp = temp->prev;
                lokasi--;
                if (temp == nullptr) {
                    break;
                }
            }
            pushCache (topUndo, createCache(baru, opcode, lokasi));
            if (temp == nullptr){
                first->prev = baru;
                baru->next = first;
                first = baru;
                return;
            }
            baru->next = temp->next;
            temp->next->prev = baru;
            baru->prev = temp;
            temp->next = baru;
        }
    }
    
}


stack createStack (){
    return nullptr;
}
bool isStackEmpty (stack top){
    return (top == nullptr)? true : false;
}
void pushCache (stack &top, ptrCache baru){
    if (isStackEmpty(top)){
        top = baru;
    } else {
        baru->next = top;
        top = baru;
    }
}
void popStack (stack &A, stack &B){
    if (A->next == nullptr){
        pushCache(B, A);
        A = nullptr;
    } else {
        stack temp = A;
        A = A->next;
        temp->next = nullptr;
        pushCache(B, temp);
    }
}
ptrCache createCache (riwayatptr data, int opcode, int lokasi){
    ptrCache baru = new cache;
    baru->data = data;
    baru->letak = lokasi;
    baru->opcode = opcode;
    baru->next = nullptr;
    return baru;
}