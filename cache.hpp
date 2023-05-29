#pragma once
#include <iostream>

#include "stack.hpp"

struct cache{
    riwayatptr node;
    int letak;
};
typedef cache* ptrcache;
using stackCache = ptrcache;

bool isCacheEmpty(stackCache top){
    return (top == nullptr)? true:false;
}
void pushCache (stackCache &top, ptrcache baru){
    if (isEmptyCache(top)){
        top = baru;
    } else {
        baru->next = top;
        top->prev = baru;
        top = baru;
    }
}
void pop (stack& top, stackCache& topcache, riwayatptr node){
    riwayatptr temp = top;
    int letak=1;
    while (temp != node){
        temp = temp->next;
        letak++;
    }
    if (isEmpty(top)){
        return ;
    } else if(top->next == nullptr){
        temp = top;
        top = nullptr;
    } else {
        temp = top;
        top = top->next;
        temp->next = nullptr;
        top->prev = nullptr;
    } 
    stackCache stk = new ptrcache;
    stk->letak = letak;
    stk->node = temp;
    push (topcache, stk);
    return;
}
