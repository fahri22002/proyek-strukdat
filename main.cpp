#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
#include "manage.hpp"


int main(){
    stack topRiwayat;
    topRiwayat = createstack();
    push(topRiwayat, createRiwayat(input()));
    showRiwayat(topRiwayat);
    push(topRiwayat, createRiwayat(input()));
    showRiwayat(topRiwayat);
    return 0;
}