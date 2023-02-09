#include "3laba/StackList.h"
#include "3laba/StackATD.h"

#include "3laba/QueueArray.h"
#include "3laba/QueueList.h"
#include "3laba/QueueATD.h"

#include "3laba/MapList.h"
#include "3laba/MapATD.h"

namespace PACK
{
    //static StackList package;
    //static StackATD package;

    //static QueueArray package;
    //static QueueList package;
    static QueueATD package;

    //static MapList package;
    //static MapATD package;
}

using namespace PACK;

#include <fstream>

void fillFromFile(std::ifstream& in)
{
    char temp;
    Object* node;

    while (in >> temp)
    {
        node = new Object(temp);  //создаем объект для добавления
        //package.PUSH(node);
        package.enqueue(*node);
    }
}

void fillMapFromFile(std::ifstream& in)
{
    char n[20], a[50];

    while (in >> n >> a)
    {
        //package.ASSIGN(n,a);
    }
}


int main() {
    std::ifstream in ("input.txt");
    std::ifstream inMap ("inputMap.txt");

    listOnCursors1::constructoR();
    listOnCursors::constructor();

    fillFromFile(in); // стек или очередь
    //fillMapFromFile(inMap);// отображение

    package.PRINT();
    //package.POP(); package.PRINT();
    package.dequeue(); package.PRINT();

    return 0;
}

