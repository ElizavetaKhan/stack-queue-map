#ifndef INC_3LAB_QUEUELIST_H
#define INC_3LAB_QUEUELIST_H
#include <fstream>
#include <iostream>
#include "/Users/elizavetahan/CLionProjects/3lab/Object.h"

class QueueList {
public:
    struct Node {

        Node* next{}; // ссылка на следующий
        struct Object obj{};

        // создание узла
        explicit Node (char obj)
        {
            this->obj.data = obj;
            this->next = this;
        }
    };

private:
    Node* tail;

public:
    QueueList();

    ~QueueList();

    // поместить х в хвост очереди Q
    void enqueue (Object& x);

    // извлекает значение из головы очереди и возвращает в качестве результата
    Object dequeue();

    // возвращает копию значения, расположенного в голове очереди
    Object FRONT();

    // возвращает истину если стек полон, иначе ложь
    static bool FULL();

    // истина, если стек пустой, иначе ложь
    bool EMPTY();

    // позволяет привести объект в исходное состояние
    void MAKENULL();

    void PRINT();
};


#endif //INC_3LAB_QUEUELIST_H
