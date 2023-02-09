#ifndef INC_1LAB_OBJECT_H
#define INC_1LAB_OBJECT_H
#include <cstring>
struct Object {
    char data{};

    explicit Object (char data) {
        this->data = data;
    };

    Object () {
        this->data = 0;
    };
};


#endif //INC_1LAB_OBJECT_H
