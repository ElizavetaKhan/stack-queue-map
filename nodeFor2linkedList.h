#ifndef INC_1LAB_NODEFOR2LINKEDLIST_H
#define INC_1LAB_NODEFOR2LINKEDLIST_H
#include "Object.h"

struct nodeFor2link {

    nodeFor2link* next{}; // ссылка на следующий
    nodeFor2link* prev{}; // ссылка на предыдущий
    struct Object obj;

    // создание узла
    explicit nodeFor2link (char obj)
    {
        strcpy(&this->obj.data, &obj);

        this->prev = nullptr;
        this->next = nullptr;
    }
};

#endif //INC_1LAB_NODEFOR2LINKEDLIST_H
