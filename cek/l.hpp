//riwayat
#include "s.hpp"

void selesai (list &LF, list &LL, list &SF, list &SL, stack &topUndo){
    if (LF != nullptr){
        list first = LF;
        LF = LF->next;
        first->next = nullptr;
        if (LF != nullptr){
            LF->prev = nullptr;
        } else {
            LL = nullptr;
        }
        if (SF != nullptr){
            SL->next = first;
            first->prev = SL;
            SL = first;
        } else {
            SF = SL = first;
        }
        pushCache (topUndo, createCache(first, 7, 1));
    }
}