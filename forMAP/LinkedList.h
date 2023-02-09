#ifndef INC_3LAB_LINKEDLIST_H
#define INC_3LAB_LINKEDLIST_H
#include "nodeList2.h"
#include <cstring>

#include <iostream>
#include <fstream>

            // СПИСОК НА ДВУСВЯЗНОМ СПИСКЕ

struct resultIsundefiNED : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};

class LinkedList {
public:
    typedef nodeList2* position; // псевдоним для Node* position

private:
    position start;
    position end;

private:
    bool findPositioN(position p); // возвращает true - если есть такой элемент, иначе false

public:
    LinkedList();

    ~LinkedList();

    void destrucT(); // удаляет все new Node

    static void constructoR(); // создание списка пустых

    void inserT(object& x, position p); // в список в position p вставить объект х

    position locatE(object& x); // возвращает position первого вхождения x в списке L

    object& retrievE(position p); // возвращает объект в position p

    position nexT(position p); // получить position, следующую за p в списке L

    position previouS(position p); // получить position, предыдущую position p в списке L

    position DeletE(position p); // удаление элемента из списка L в position p

    void makeNulL(); // делает список L пустым ( не содержащим элементов ) - вызов destruct

    position firsT(); // возвращает position первого элемента списка - start

    static position enD() ; // возвращает position после последнего - end->next

    void printLisT(); // выводит список на экран

};


#endif //INC_3LAB_LINKEDLIST_H
