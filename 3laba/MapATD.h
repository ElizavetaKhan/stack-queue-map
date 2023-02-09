#ifndef INC_3LAB_MAPATD_H
#define INC_3LAB_MAPATD_H
#include "/Users/elizavetahan/CLionProjects/3lab/forMAP/arraY1.h"
#include "/Users/elizavetahan/CLionProjects/3lab/forMAP/list1.h"
#include "/Users/elizavetahan/CLionProjects/3lab/forMAP/LinkedList.h"
#include "/Users/elizavetahan/CLionProjects/3lab/forMAP/listOnCursors1.h"

namespace LIST3 {
    //static list1 ATD;
    static arraY1 ATD;
    //static LinkedList ATD;
    //static listOnCursors1 ATD;
}
typedef arraY1 constructor3;

using namespace LIST3;

class MapATD {
private:
    typedef int pos;

    //pos zero = nullptr;
    pos zero = 0;

public:
    MapATD();

    ~MapATD();

    //делает отображение пустым
    void MAKENULL();

    //Если d есть в отображении, то без каких-либо проверок M(d) = r (присваивается новое значение).
    // Иначе, если нет в отображении, то создается новая пара M(d) = r
    void ASSIGN(char d[20], char r[50]);

    //возвращает истину, если определено M(d) = r, в r записывается значение
    // и ложь если пара не определена.
    bool COMPUTE(char d[20], char r[50]);

    void PRINT();
};


#endif //INC_3LAB_MAPATD_H
