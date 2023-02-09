#ifndef INC_3LAB_NODELIST2_H
#define INC_3LAB_NODELIST2_H

#include "object.h"

struct nodeList2 {

    nodeList2* next{}; // ссылка на следующий
    nodeList2* prev{}; // ссылка на предыдущий
    struct object obj; // имя и адрес

    // создание узла
    nodeList2 (char n[20], char a[50])
    {
        strcpy(this->obj.name, n);
        strcpy(this->obj.adress, a);

        this->prev = nullptr;
        this->next = nullptr;
    }
};

#endif //INC_3LAB_NODELIST2_H
