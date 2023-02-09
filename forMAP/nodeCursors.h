#ifndef INC_3LAB_NODECURSORS_H
#define INC_3LAB_NODECURSORS_H

#include "object.h"

struct NodeCursors {

    int next; // номер следующего элемента
    struct object obj; // имя и адрес

    // создание узла
    NodeCursors (char n[20], char a[50])
    {
        if (n && a) { // если не nullptr
            strcpy(this->obj.name, n);
            strcpy(this->obj.adress,a);
        }

        this->next = 0;
    }
};

#endif //INC_3LAB_NODECURSORS_H
