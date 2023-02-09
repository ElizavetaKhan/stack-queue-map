#include "listOnCursors1.h"

listOnCursors1::listOnCursors1()
{
    this->heaD = 0;
}

listOnCursors1::~listOnCursors1()
{
    makeNulL();
}


void listOnCursors1::constructoR()
{
    space = 1;
    array[1] = new NodeCursors(nullptr, nullptr);

    for (position i = 2; i <= 25; ++i) { // заполняем список пустых
        array[i] = new NodeCursors(nullptr, nullptr);
        array[i-1]->next = i;
    }
}

listOnCursors1::position listOnCursors1::takeMemorY()
{
    position temp = space;
    space = array[space]->next;

    return temp;
}

void listOnCursors1::giveMemorY(position node)
{
    position temp = space;
    space = node;

    array[space]->next = temp;
}

listOnCursors1::position listOnCursors1::findPositioN(position p) const
{
    if (!array[p] || this->heaD == 0) // если такого элемента нет или список М пустой
        return 0;

    if (p == this->heaD)
        return this->heaD;

    position cur = this->heaD;
    position prev = cur;

    while (array[cur]) {
        if (p == cur)
            return prev;

        prev = cur;
        cur = array[cur]->next;
    }

    return 0;
}

listOnCursors1::position listOnCursors1::findLasT() const
{
    if (this->heaD == 0) // если список не заполнен
        return 0;

    position temp = this->heaD;
    position prev;

    while (temp) {
        prev = temp;
        temp = array[temp]->next;
    }

    return prev;
}

void listOnCursors1::inserT(struct object& x, position p)
{
    if (this->heaD == 0) { // если первый элемент списка
        NodeCursors* node1;
        node1 = new NodeCursors(x.name,x.adress); // узел для вставки в голову

        position node = this->takeMemorY(); // получили позицию, куда можем положить объект
        this->heaD = node; // первый элемент - голова

        array[node]->obj = &node1->obj;
        array[node]->next = 0;
        return;
    }

    if (this->findPositioN(p) == 0) // если такой позиции нет в списке - вставка в конец
        // в р передаем сразу takeMemory()
    {
        array[p]->obj = x; // копируем имя и адрес в элемент с позицией р

        array[this->findLasT()]->next = p;
        array[p]->next = 0;
    }

    else { // если вставляем не в конец и нашли позицию р

        // берем память под новый узел
        position pos = takeMemorY();

        // сохраняем имя и адрес элемента с позицией р
        array[pos]->obj = &array[p]->obj;

        // копируем имя и адрес в элемент с позицией р
        array[p]->obj = x;

        array[pos]->next = array[p]->next;
        array[p]->next = pos;
    }
}

listOnCursors1::position listOnCursors1::DeletE(position p)
{
    position m = this->findPositioN(p); // проверяем наличие позиции и сохраняем позицию перед р

    if (m == 0) // нет такой позиции
        return p;

    position temp = array[p]->next; // сохраняем позицию после р

    if (p == this->heaD){ // если голова
        this->heaD = array[this->heaD]->next; // переопределяем голову
        giveMemorY(p);
        return temp; // возвращаем элемент после удаленного

    } if (array[p]->next == 0){ // если последний элемент
        array[m]->next = 0;
        giveMemorY(p);
        return temp; // возвращаем элемент после удаленного

    } else { // если элемент не heaD и не last
        array[m]->next = array[p]->next;
        giveMemorY(p);
        return temp; // возвращаем элемент после удаленного
    }
}

listOnCursors1::position listOnCursors1::locatE(object& x) const
{
    position temp = this->heaD; // temp - позиция первого узла

    while (array[temp]) {
        if (array[temp]->obj == x)    // ЗДЕСЬ РАБОТАЕТ ПЕРЕГРУЗКА ==
            return temp;
        temp = array[temp]->next;
    }

    return 0;
}

object& listOnCursors1::retrievE(position p)
{
    if (this->findPositioN(p) == 0)
        throw resultIsUndefinED(); // если не существует или p=end(L)

    return array[p]->obj;
}

listOnCursors1::position listOnCursors1::nexT(position p)
{
    if (this->findPositioN(p) == 0)
        throw resultIsUndefinED(); // если р не существует или р = end(L)

    return array[p]->next;
}

listOnCursors1::position listOnCursors1::enD()
{
    return takeMemorY();
}

listOnCursors1::position listOnCursors1::previouS(position p)
{
    position m = this->findPositioN(p); // предыдущий за p храним

    if (m == this->heaD || m == 0) // если первый или не существует такой позиции
        throw resultIsUndefinED();

    return m;
}

void listOnCursors1::makeNulL() // перемещаем все элементы в список пустых
{
    if (this->heaD) {
        position temp = this->heaD;
        position n = array[temp]->next; // храним номер следующего за temp элемента

        while (n != 0) {
            giveMemorY(temp);
            temp = n;
            n = array[n]->next;
        }
        giveMemorY(temp);
    }
    this->heaD = 0;
}

listOnCursors1::position listOnCursors1::firsT() const
{
    return this->heaD;
}

void listOnCursors1::printLisT() const
{
    std::cout << std::endl;

    if (this->heaD == 0)
        throw resultIsUndefinED();
    position temp = this->heaD;

    while (temp != 0) {
        std::cout << array[temp]->obj.name << " - " <<  array[temp]->obj.adress << std::endl;
        temp = array[temp]->next;
    }
}