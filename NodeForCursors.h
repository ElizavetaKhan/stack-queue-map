#ifndef INC_1LAB_NODEFORCURSORS_H
#define INC_1LAB_NODEFORCURSORS_H
#include "Object.h"

 struct NodeForCursors {

    int next{}; // номер следующего элемента
    struct Object obj; // имя и адрес

    // создание узла
    explicit NodeForCursors (char obj)
    {
        if (obj != 0) { // если не nullptr
            strcpy(&this->obj.data, &obj);
        }

        this->next = 0;
    }
};

#endif //INC_1LAB_NODEFORCURSORS_H
