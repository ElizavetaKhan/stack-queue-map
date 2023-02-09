#ifndef INC_1LAB_NODE_H
#define INC_1LAB_NODE_H
#include "Object.h"

struct Node {

    struct Object obj;

    // создание узла
    explicit Node (char obj)
    {
        strcpy(&this->obj.data, &obj);
    }
};

#endif //INC_1LAB_NODE_H
