#ifndef INC_3LAB_MAPLIST_H
#define INC_3LAB_MAPLIST_H
#include <iostream>
#include "/Users/elizavetahan/CLionProjects/3lab/forMAP/object.h"
#include <fstream>

class MapList {
public:
    struct Node {

        Node* next{}; // ссылка на следующий
        struct object obj{};

        // создание узла
        Node(char n[20], char a[50])
        {
            strcpy(this->obj.name, n);
            strcpy(this->obj.adress, a);

            this->next = nullptr;
        }
    };

private:
    Node* head;

public:
    MapList();

    ~MapList();

    //делает отображение пустым
    void MAKENULL();

    //Если d есть в отображении, то без каких-либо проверок M(d) = r (присваивается новое значение).
    // Иначе, если нет в отображении, то создается новая пара M(d) = r
    void ASSIGN(char d[20], char r[50]);

    //возвращает истину, если определено M(d) = r, в r записывается значение
    // и ложь если пара не определена.
    bool COMPUTE(char d[20], char r[50]);

    Node* findName(object& obj);

    void PRINT();
};

#endif //INC_3LAB_MAPLIST_H
