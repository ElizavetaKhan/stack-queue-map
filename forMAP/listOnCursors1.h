#ifndef INC_3LAB_LISTONCURSORS1_H
#define INC_3LAB_LISTONCURSORS1_H
#include "nodeCursors.h"

#include <iostream>
#include <fstream>

struct resultIsUndefinED : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};

class listOnCursors1 {
public:
    typedef int position; // псевдоним для int position

private:
    static inline NodeCursors* array[26]{}; // список пустых
    static inline position space = 0; // точка входа в список пустых

    position heaD;

private:
    // возвращает элемент до p или же 0 - если такой позиции нет
    position findPositioN(position p) const;

    // возвращает позицию последнего элемента списка
    position findLasT() const;

    // взять память из списка пустых
    position takeMemorY();

    // добавляет узел в список пустых
    void giveMemorY(position node);

public:
    listOnCursors1();

    ~listOnCursors1();

    static void constructoR(); // создание списка пустых

    void inserT(object& x, position p); // в position p вставить x

    position DeletE(position p); // удаление элемента в position p, возвращает p, если такой позиции нет

    position locatE(object& x) const; // возвращает position первого вхождения x

    object& retrievE(position p); // возвращает объект в position p

    position nexT(position p); // получить position, следующую за p

    position enD(); // возвращает position после последнего

    position previouS(position p); // получить position перед p

    void makeNulL(); // делает М пустым ( не содержащим элементов ).

    position firsT() const ; // возвращает position head. Если список пустой, то возвращает 0

    void printLisT() const; // выводит на экран.
};


#endif //INC_3LAB_LISTONCURSORS1_H
