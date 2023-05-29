//undo redo
#pragma once
#include <iostream>
#include "s.hpp"

void undo (stack &topUndo, stack &topRedo, list &first){
    if (isStackEmpty(topUndo)){
        return;
    } else if (topUndo->opcode == 2){
        if (topUndo->letak == 1){
            first = first->next;
            if (first != nullptr && first->prev != nullptr){
                first->prev->next = nullptr;
                first->prev = nullptr;
            }
            popStack (topUndo, topRedo);
        } else {
            list temp = first;
            for (int i = 1; i< topUndo->letak; i++){
                temp = temp->next;
            }
            if (temp->next == nullptr){
                temp->prev->next = nullptr;
                temp->prev = nullptr;
                popStack (topUndo, topRedo);
            } else {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                temp->next = nullptr;
                temp->prev = nullptr;
                popStack (topUndo, topRedo);
            }
        }
        
    }
}
void redo (stack &topUndo, stack &topRedo, list &first, list &last){
    std::cout<<topRedo->opcode<<topRedo->letak<<topRedo->data->data.prior;
    if (isStackEmpty(topRedo)){
        return;
    } else if (topRedo->opcode == 2){
        if (topRedo->letak == 1){
            first = topRedo->data;
            popStack (topRedo, topUndo);
        } else {
            list temp = first;
            for (int i = 1; i< topRedo->letak; i++){
                temp = temp->next;
            }
            if (temp == nullptr){
                last->next = topRedo->data;
                topRedo->data->prev = last;
                last = last->next;
                popStack (topRedo, topUndo);
            } else {
                topRedo->data->next = temp;
                topRedo->data->prev = temp->prev;
                temp->prev->next = topRedo->data;
                temp->prev = topRedo->data;
                popStack (topRedo, topUndo);
            }
        }
        
    }
}