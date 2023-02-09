#ifndef INC_1LAB_LINKEDLIST2_H
#define INC_1LAB_LINKEDLIST2_H
#include "nodeFor2linkedList.h"
#include <cstring>

#include <iostream>
#include <fstream>

            // СПИСОК НА ДВУСВЯЗНОМ СПИСКЕ

struct resultIsundefined : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};

class linkedList2 {
public:
    typedef nodeFor2link* position; // псевдоним для Node* position

private:
    position start;
    position End;

private:
    bool findPosition(position p); // возвращает true - если есть такой элемент, иначе false

public:
    linkedList2();

    ~linkedList2(); // вызывает destruct()

    void destruct(); // удаляет все new Node

    static void constructor(); // создание списка пустых

    void insert(Object& x, position p); // в список в position p вставить объект х

    position locate(Object& x); // возвращает position первого вхождения x в списке L

    Object* retrieve(position p); // возвращает объект в position p

    position next(position p); // получить position, следующую за p в списке L

    position previous(position p); // получить position, предыдущую position p в списке L

    position Delete(position p); // удаление элемента из списка L в position p

    void makeNull(); // делает список L пустым ( не содержащим элементов ) - вызов destruct

    position first(); // возвращает position первого элемента списка - start

    static position end() ; // возвращает position после последнего - end->next

    void printList();

};


#endif //INC_1LAB_LINKEDLIST2_H
