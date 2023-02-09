#include "listOnCursors.h"

listOnCursors::listOnCursors()
{
    this->heaD = 0;
}

listOnCursors::~listOnCursors()
{
    makeNull();
}

void listOnCursors::constructor()
{
    space = 1;
    array[1] = new NodeForCursors(0);

    for (position i = 2; i <= 25; ++i) { // заполняем список пустых
        array[i] = new NodeForCursors(0);
        array[i-1]->next = i;
    }
}

listOnCursors::position listOnCursors::takeMemory()
{
    position temp = space;
    space = array[space]->next;

    return temp;
}

void listOnCursors::giveMemory(position node)
{
    position temp = space;
    space = node;

    array[space]->next = temp;
}

listOnCursors::position listOnCursors::findPosition(position p) const
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

listOnCursors::position listOnCursors::findLast() const
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

void listOnCursors::insert(Object& x, position p)
{
    if (this->heaD == 0) { // если первый элемент списка
        NodeForCursors* node1;
        node1 = new NodeForCursors(x.data); // узел для вставки в голову

        position node = takeMemory(); // получили позицию, куда можем положить объект
        this->heaD = node; // первый элемент - голова

        array[node]->obj = node1->obj;
        array[node]->next = 0;
        return;
    }

    if (this->findPosition(p) == 0) // если такой позиции нет в списке - вставка в конец
        // в р передаем сразу takeMemory()
    {
        array[p]->obj.data = x.data; // копируем имя и адрес в элемент с позицией р

        array[this->findLast()]->next = p;
        array[p]->next = 0;
    }

    else { // если вставляем не в конец и нашли позицию р

        // берем память под новый узел
        position pos = takeMemory();

        // сохраняем имя и адрес элемента с позицией р
        array[pos]->obj = array[p]->obj;

        // копируем имя и адрес в элемент с позицией р
        array[p]->obj.data = x.data;

        array[pos]->next = array[p]->next;
        array[p]->next = pos;
    }
}

listOnCursors::position listOnCursors::Delete(position p)
{
    position m = this->findPosition(p); // проверяем наличие позиции и сохраняем позицию перед р

    if (m == 0) // нет такой позиции
        return p;

    position temp = array[p]->next; // сохраняем позицию после р

    if (p == this->heaD){ // если голова
        this->heaD = array[this->heaD]->next; // переопределяем голову
        giveMemory(p);
        return temp; // возвращаем элемент после удаленного

    } if (array[p]->next == 0){ // если последний элемент
        array[m]->next = 0;
        giveMemory(p);
        return temp; // возвращаем элемент после удаленного

    } else { // если элемент не heaD и не last
        array[m]->next = array[p]->next;
        giveMemory(p);
        return temp; // возвращаем элемент после удаленного
    }
}

listOnCursors::position listOnCursors::locate(Object& x) const
{
    position temp = this->heaD; // temp - позиция первого узла

    while (array[temp]) {
        if (array[temp]->obj.data == x.data)
            return temp;
        temp = array[temp]->next;
    }

    return 0;
}

Object& listOnCursors::retrieve(position p)
{
    if (this->findPosition(p) == 0)
        throw resultIsUndefineD(); // если не существует или p=end(L)

    return array[p]->obj;
}

listOnCursors::position listOnCursors::next(position p)
{
    if (this->findPosition(p) == 0)
        throw resultIsUndefineD(); // если р не существует или р = end(L)

    return array[p]->next;
}

listOnCursors::position listOnCursors::end()
{
    return takeMemory();
}

listOnCursors::position listOnCursors::previous(position p)
{
    position m = this->findPosition(p); // предыдущий за p храним

    if (p == this->heaD || m == 0) // если первый или не существует такой позиции
        throw resultIsUndefineD();

    return m;
}

void listOnCursors::makeNull() // перемещаем все элементы в список пустых
{
    if (this->heaD) {
        position temp = this->heaD;
        position n = array[temp]->next; // храним номер следующего за temp элемента

        while (n != 0) {
            giveMemory(temp);
            temp = n;
            n = array[n]->next;
        }
        giveMemory(temp);
    }
    this->heaD = 0;
}

listOnCursors::position listOnCursors::first() const
{
    return this->heaD;
}

void listOnCursors::printList() const
{
    std::cout << std::endl;

    if (this->heaD == 0)
        throw resultIsUndefineD();
    position temp = this->heaD;


    while (temp != 0) {
        std::cout << array[temp]->obj.data << "   ";
        temp = array[temp]->next;
    }

    std::cout << std::endl;
}
