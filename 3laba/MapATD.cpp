#include "MapATD.h"

MapATD::MapATD()
{
    ATD = constructor3();
}

MapATD::~MapATD()
{
    ATD.makeNulL();
}

void MapATD::MAKENULL()
{
    ATD.makeNulL();
}

void MapATD::ASSIGN(char *d, char *r)
{
    object* node = new object(d, r);

    // есть ли в списке уже такое d
    pos pos = ATD.locatE(*node);

    if (pos != zero) { // если есть
        strcpy(ATD.retrievE(pos).adress, r);

    } else { // если нужно вставить новый узел в список
        ATD.inserT(*node,ATD.firsT());
    }
}

bool MapATD::COMPUTE(char *d, char *r)
{
    object* node = new object(d,r);
    pos pos = ATD.locatE(*node);

    // если есть такое d в списке
    if (pos != zero) {
        strcpy(r,ATD.retrievE(pos).adress);
        return true;
    }

    return false;
}

void MapATD::PRINT()
{
    ATD.printLisT();
}
