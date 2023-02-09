#ifndef INC_3LAB_NODELIST_H
#define INC_3LAB_NODELIST_H

#include "object.h"

struct nodeList {

    nodeList* next{}; // ссылка на следующий
    struct object obj; // имя и адрес

    // создание узла
    nodeList (char n[20], char a[50])
    {
        strcpy(this->obj.name, n);
        strcpy(this->obj.adress, a);

        this->next = nullptr;
    }
};

#endif //INC_3LAB_NODELIST_H
