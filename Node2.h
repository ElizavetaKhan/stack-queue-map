#ifndef INC_1LAB_NODE2_H
#define INC_1LAB_NODE2_H
#include "Object.h"

struct Node1 {

    Node1* next{}; // ссылка на следующий
    struct Object obj;

    // создание узла
    explicit Node1 (char obj)
    {
        strcpy(&this->obj.data, &obj);
        this->next = nullptr;
    }
};
#endif //INC_1LAB_NODE2_H
