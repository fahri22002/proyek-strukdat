//undo redo
#pragma once
#include <iostream>
#include "s.hpp"

void undo (stack &topUndo, stack &topRedo, list &first, list& last){
    if (isStackEmpty(topUndo)){
        return;
    } else if (topUndo->opcode == 2){
        if (topUndo->letak == 1){
            first = first->next;
            if (first != nullptr && first->prev != nullptr){
                first->prev->next = nullptr;
                first->prev = nullptr;
            }
            if (first == nullptr){
                last = nullptr;
            }
            popStack (topUndo, topRedo);
        } else {
            list temp = first;
            for (int i = 1; i< topUndo->letak; i++){
                temp = temp->next;
            }
            if (temp->next == nullptr){
                last = temp->prev;
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
        
    } else if (topUndo->opcode == 3){
        if (topUndo->letak == 1){
            if (first == nullptr){
                first = last = topUndo->data;
                popStack (topUndo, topRedo);
            } else {
                topUndo->data->next = first;
                first->prev = topUndo->data;
                first = topUndo->data;
                popStack (topUndo, topRedo);
            }
        } else {
            list temp = first;
            for (int i = 1; i< topUndo->letak; i++){
                temp = temp->next;
            }
            if (temp == nullptr){
                last->next = topUndo->data;
                topUndo->data->prev = last;
                last = topUndo->data;
                popStack (topUndo, topRedo);
            } else {
                topUndo->data->next = temp;
                topUndo->data->prev = temp->prev;
                temp->prev->next = topUndo->data;
                temp->prev = topUndo->data;
                popStack (topUndo, topRedo);
            }
        }
    } else if (topUndo->opcode == 4){
        list temp = first;
        for (int i = 1; i< topUndo->letak; i++){
            temp = temp->next;
        }
        topUndo->data->next = temp->next;
        topUndo->data->prev = temp->prev;
        if (temp->next != nullptr){
            temp->next->prev = topUndo->data;
        } else {
            last = topUndo->data;
        }
        if (temp->prev != nullptr){
            temp->prev->next = topUndo->data;
        } else {
            first = topUndo->data;
        }
        temp->next = nullptr;
        temp->prev = nullptr;
        pushCache(topRedo, createCache(temp, 4, topUndo->letak));
        stack del = topUndo;
        topUndo = topUndo->next;
        delete del;
    }
}
void redo (stack &topUndo, stack &topRedo, list &first, list &last){
    
    if (isStackEmpty(topRedo)){
        return;
    } else if (topRedo->opcode == 2){
        if (topRedo->letak == 1){
            if (first == nullptr){
                first = topRedo->data;
                last = first;
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
        
    } else if (topRedo->opcode == 3){
        if (topRedo->letak == 1){
            first = first->next;
            if (first != nullptr && first->prev != nullptr){
                first->prev->next = nullptr;
                first->prev = nullptr;
            }
            if (first == nullptr){
                last = nullptr;
            }
            popStack (topRedo, topUndo);
        } else {
            list temp = first;
            for (int i = 1; i< topRedo->letak; i++){
                temp = temp->next;
            }
            if (temp->next == nullptr){
                last = temp->prev;
                temp->prev->next = nullptr;
                temp->prev = nullptr;
                popStack (topRedo, topUndo);
            } else {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                temp->next = nullptr;
                temp->prev = nullptr;
                popStack (topRedo, topUndo);
            }
        }
    } else if (topRedo->opcode == 4){
        list temp = first;
        for (int i = 1; i< topRedo->letak; i++){
            temp = temp->next;
        }
        topRedo->data->next = temp->next;
        topRedo->data->prev = temp->prev;
        if (temp->next != nullptr){
            temp->next->prev = topRedo->data;
        } else {
            last = topRedo->data;
        }
        if (temp->prev != nullptr){
            temp->prev->next = topRedo->data;
        } else {
            first = topRedo->data;
        }
        temp->next = nullptr;
        temp->prev = nullptr;
        pushCache(topUndo, createCache(temp, 4, topRedo->letak));
        stack del = topRedo;
        topRedo = topRedo->next;
        delete del;
    }
}
void delRedo (stack &topRedo){
    if (!isStackEmpty(topRedo)){
        bool mark = false;
        while (topRedo != nullptr){
            if (topRedo->opcode == 3){
                stack del = topRedo;
                topRedo = topRedo->next;
                delete del;
            } else if (topRedo->opcode == 7 && topRedo->next->opcode == 7){
                stack del = topRedo;
                topRedo = topRedo->next;
                del->next = nullptr;
                delete del->data;
                delete del;
                del = topRedo;
                topRedo = topRedo->next;
                delete del;
            } else {
                stack del = topRedo;
                topRedo = topRedo->next;
                listBarang temp = del->data->data.unit, delunit;
                while (temp != nullptr){
                    delunit = temp;
                    temp = temp->next;
                    delunit->next = nullptr;
                    delete delunit;
                }
                del->next = nullptr;
                delete del->data;
                delete del;
            }
        }
    }
}