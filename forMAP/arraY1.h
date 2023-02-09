#ifndef INC_3LAB_ARRAY1_H
#define INC_3LAB_ARRAY1_H
#include "nodeArr.h"

#include <iostream>
#include <fstream>

            // СПИСОК НА МАССИВЕ

struct ResultisUndefined : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};

class arraY1 {
public:
    typedef int position; // псевдоним для int position

private:
    position last;
    NodeArr* A[20]{};

public:
    arraY1();

    ~arraY1();

    void destrucT();

    static void constructoR(); // создание списка пустых

    void inserT(object& x, position p); // в массив в position p вставить x

    position enD() const; // возвращает position после последнего

    position locatE(object& x); // возвращает position первого вхождения x в массиве A

    object& retrievE(position p); // возвращает объект в position p

    position nexT(position p) const ; // получить position, следующую за p в массиве A

    static position previouS(position p); // получить position, предыдущую position p в массиве A

    void DeletE(position p); // удаление элемента из массива A в position p

    void makeNulL(); // делает массив А пустым ( не содержащим элементов ).

    position firsT() const ; // возвращает position первого элемента массива. Если массив пустой, то возвращает end(А).

    void printLisT(); // выводит массив на экран.

};

#endif //INC_3LAB_ARRAY1_H
