#ifndef INC_3LAB_LIST1_H
#define INC_3LAB_LIST1_H
#include "nodeList.h"
#include <cstring>

#include <iostream>
#include <fstream>

            // СПИСОК НА СВЯЗНОМ СПИСКЕ

struct REsultIsUndefined : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};


class list1 {
public:
    typedef nodeList* position; // псевдоним для Node* position

private:
    position head;

private:
    position findPositioN(position p); // возвращает элемент до p или же NULLPTR - если такой позиции нет

    position findLasT(); // возвращает позицию последнего элемента списка

public:
    list1();

    ~list1();

    static void constructoR(); // создание списка пустых

    void destrucT(); // удаляет все new Node

    void inserT(object& x, position p); // в список в position p вставить x

    position locatE(object& x); // возвращает position первого вхождения x в списке L

    object& retrievE(position p); // возвращает объект в position p

    position nexT(position p); // получить position, следующую за p в списке L

    position previouS(position p); // получить position, предыдущую position p в списке L

    position DeletE(position p); // удаление элемента из списка L в position p

    void makeNulL(); // делает список L пустым ( не содержащим элементов ) - вызов destruct

    position firsT(); // возвращает position первого элемента списка. Если список пустой, то возвращает end(L).

    static position enD() ; // возвращает position после последнего

    void printLisT(); // выводит список на экран

};


#endif //INC_3LAB_LIST1_H
