#ifndef INC_3LAB_QUEUEARRAY_H
#define INC_3LAB_QUEUEARRAY_H
#include "/Users/elizavetahan/CLionProjects/3lab/Object.h"
#include <fstream>
#include <iostream>

class QueueArray {
private:
    char* array;

    int front;
    int tail;
    int count = 12; // свободная память
private:
    int next(int pos);

public:
    QueueArray();

    ~QueueArray();

    // поместить х в хвост очереди Q
    void enqueue (Object& x);

    // извлекает значение из головы очереди и возвращает в качестве результата
    char dequeue();

    // возвращает копию значения, расположенного в голове очереди
    char FRONT();

    // возвращает истину если стек полон, иначе ложь
    bool FULL();

    // истина, если стек пустой, иначе ложь
    bool EMPTY();

    // позволяет привести объект в исходное состояние
    void MAKENULL();

    void PRINT();
};


#endif //INC_3LAB_QUEUEARRAY_H
