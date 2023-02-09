#ifndef INC_3LAB_STACKATD_H
#define INC_3LAB_STACKATD_H
#include "../array.h"
#include "../list.h"
#include "../linkedList2.h"
#include "../listOnCursors.h"

namespace LIST1 {
    //static list ATD;
    //static array ATD;
    //static linkedList2 ATD;
    static listOnCursors ATD;
}

typedef listOnCursors constructor;

using namespace LIST1;

class StackATD {

public:
    // заполняем ATD из файла
    StackATD();

    ~StackATD();

    // поместить х на вершину стека. Если на вершине стека уже что-то есть, то оно проталкивается дальше.
    void PUSH(Object& x);

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


#endif //INC_3LAB_STACKATD_H
