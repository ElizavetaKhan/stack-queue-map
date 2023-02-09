#ifndef INC_3LAB_QUEUEATD_H
#define INC_3LAB_QUEUEATD_H
#include "../array.h"
#include "../list.h"
#include "../linkedList2.h"
#include "../listOnCursors.h"

namespace LIST2 {
    //static list ATD;
    //static array ATD;
    //static linkedList2 ATD;
    static listOnCursors ATD;
}
typedef listOnCursors constructor2;

using namespace LIST2;

class QueueATD {
public:
    // заполняем ATD из файла
    QueueATD();

    ~QueueATD();

    // поместить х в хвост очереди Q
    void enqueue (Object& x);

    // извлекает значение из головы очереди и возвращает в качестве результата
    Object dequeue();

    // возвращает копию значения, расположенного в голове очереди
    Object FRONT();

    // возвращает истину если стек полон, иначе ложь
    static bool FULL();

    // истина, если стек пустой, иначе ложь
    bool EMPTY() const;

    // позволяет привести объект в исходное состояние
    void MAKENULL();

    void PRINT();
};


#endif //INC_3LAB_QUEUEATD_H
