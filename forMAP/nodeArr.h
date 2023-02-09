#ifndef INC_3LAB_NODEARR_H
#define INC_3LAB_NODEARR_H
#include "object.h"

struct NodeArr {

    struct object obj; // имя и адрес

    // создание узла
    NodeArr (char n[20], char a[50])
    {
        strcpy(this->obj.name, n);
        strcpy(this->obj.adress, a);
    }
};

#endif //INC_3LAB_NODEARR_H
