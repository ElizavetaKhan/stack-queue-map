#include "QueueArray.h"

QueueArray::QueueArray()
{
    front = 0;
    tail = count-1;
    array = new char[count];
}

QueueArray::~QueueArray()
{
    this->MAKENULL();
}

void QueueArray::enqueue(Object& x)
{
    if (next(tail) == front) { // если первый элемент массива
        array[front] = x.data;
        tail = front;

    } else {
        tail = next(tail);
        array[tail] = x.data;
    }
}

char QueueArray::dequeue()
{
    if (front == tail) { // если один элемент
        char temp = array[front]; // сохраняем значение головы
        front = 0;
        tail = count - 1;

        return temp;

    } else {
        char temp = array[front]; // сохраняем значение головы
        front = next(front);

        return temp;
    }
}

int QueueArray::next(int pos)
{
    return (pos + 1) % count;
}

char QueueArray::FRONT()
{
    return array[front];
}

bool QueueArray::FULL()
{
    return next(next(tail)) == front;
}

bool QueueArray::EMPTY()
{
    return next(tail) == front;
}

void QueueArray::MAKENULL()
{
    delete[] array;
}

void QueueArray::PRINT()
{
    std::cout <<  std::endl;

    for (int i = front; i != tail; i = next(i))
        std::cout << array[i] << "   ";

    std::cout << array[tail] << std::endl;
}