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
    
    if (isStackEmpty(topRedo)){
        return;
    } else if (topRedo->opcode == 2){
        if (topRedo->letak == 1){
            if (first == nullptr){
                first = topRedo->data;
            } else {
                topRedo->data->next = first;
                first->prev = topRedo->data;
                first = first->prev;
            }
            
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
void delRedo (stack &topRedo){
    std::cout<<"A";
    if (!isStackEmpty(topRedo)){
        while (topRedo != nullptr){
            stack del = topRedo;
            topRedo = topRedo->next;
            delete del;
            std::cout<<"b";
        }
    }
    std::cout<<"A";
}