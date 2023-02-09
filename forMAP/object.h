#ifndef INC_3LAB_OBJECT_H
#define INC_3LAB_OBJECT_H
#include <cstring>

struct object {
    char name[20]{};
    char adress[50]{};

    // сравнивает на равенство только имена
    friend bool operator== (object& first, object& second) { // перегрузка оператора ==
        size_t f = strlen(first.name);
        size_t s = strlen(second.name);

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < s; ++j) {
                if (first.name[i] != second.name[j])
                    return false;
                else ++i;
            }
        }
        return true;
    };

    object& operator= (object* second) { // перегрузка оператора ==
        strcpy(this->name, second->name);
        strcpy(this->adress, second->adress);

        return *this;
    };

    object(char n[20], char a[50]) {
        strcpy(this->name, n);
        strcpy(this->adress,a);
    };

    object(){};
};

#endif //INC_3LAB_OBJECT_H
