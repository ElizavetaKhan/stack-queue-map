#ifndef INC_3LAB_STACKLIST_H
#define INC_3LAB_STACKLIST_H
#include <fstream>
#include <iostream>
#include "/Users/elizavetahan/CLionProjects/3lab/Object.h"

class StackList {
public:
    struct Node1 {

        Node1* next{}; // ссылка на следующий
        struct Object obj{};

        // создание узла
        explicit Node1 (char obj)
        {
            this->obj.data = obj;
            this->next = nullptr;
        }
    };

private:
    Node1* peak;

public:
    StackList();

    ~StackList();

    // поместить х на вершину стека. Если на вершине стека уже что-то есть, то оно проталкивается дальше.
    void PUSH(Object x);

    // удаляет значение с вершины стека, возвращая его в качестве результата
    Object POP();

    // возвращает значение, расположенное на вершине стека
    Object TOP();

    // возвращает истину если стек полон, иначе ложь
    static bool FULL();

    // истина, если стек пустой, иначе ложь
    bool EMPTY();

    // позволяет привести объект в исходное состояние
    void MAKENULL();

    void PRINT();
};


#endif //INC_3LAB_STACKLIST_H
