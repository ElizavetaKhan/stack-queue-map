#include "arraY1.h"

arraY1::arraY1()
{
    this->last = -1;
}

arraY1::~arraY1()
{
    destrucT();
}

void arraY1::destrucT()
{
    if (last == -1)
        return;

    for (position i = 0; i <= last; ++i) {
        delete A[i];
    }

    last = -1;
}

void arraY1::inserT(object& x, position p)
{
    last++;

    for (position i = last; i > p; i--)
    {
        A[i] = A[i-1];
    }

    A[p] = new NodeArr(x.name, x.adress);
}

arraY1::position arraY1::enD() const
{
    return last+1;
}

arraY1::position arraY1::locatE(object& x)
{
    position cur = 0; // cur - позиция первого узла

    while(cur <= last) {
        if (x == A[cur]->obj)
            return cur;

        cur++;
    }

    return 0;
}

object& arraY1::retrievE(position p) // возвращает объект в позиции p
{
    if (p > last)
        throw ResultisUndefined(); // если не существует или p = end(А)

    else return A[p]->obj;
}

arraY1::position arraY1::nexT(position p) const
{
    if (p < last) { // если все ок
        return p+1;
    }
    else if (p == last) { // если последний элемент
        return enD();
    }
    else{
        throw ResultisUndefined(); // если р не существует или р = end(А)
    }
}

arraY1::position arraY1::previouS(position p)
{
    if (p > 0)
        return p-1;
    else
        throw ResultisUndefined(); // если p = end(А)
}

void arraY1::DeletE(position p)
{
    if (p < 0 || p > last)
        throw ResultisUndefined();// p не существует или p = end(А), то результат не определен.

    for (int i = p; i < last+1; ++i)
        A[i] = A[i+1];

    last--;
}

void arraY1::makeNulL()
{
    destrucT();
}

arraY1::position arraY1::firsT() const
{
    if (last > -1)
        return 0;
    else
        return enD();
}

void arraY1::printLisT()
{
    std::cout << std::endl;

    if (last == -1) // если нет элементов массива
        throw ResultisUndefined();

    for (position i = 0; i <= last; i++)
    {
        std::cout << A[i]->obj.name << " - " << A[i]->obj.adress << std::endl;
    }
}

void arraY1::constructoR() {

}
