#include "list1.h"

list1::list1()
{
    this->head = nullptr;
}

list1::~list1()
{
    destrucT();
}

void list1::destrucT()
{
    if (!head)
        return;

    nodeList* currentNode = head;

    while (currentNode) {
        nodeList* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
}

list1::position list1::findPositioN(position p)
{
    if (p == head) // если голова
        return head;

    position t = head;
    position prev = head;

    while (t) {
        if (p == t)
            return prev;

        prev = t;
        t = t->next;
    }
    return nullptr;
}

list1::position list1::findLasT()
{
    position temp = head;
    position prev;

    while (temp) {
        prev = temp;
        temp = temp->next;
    }

    return prev;
}

void list1::inserT(object& x, position p)
{
    if (!head) {
        nodeList *node;
        node = new nodeList(x.name, x.adress); // первый узел определяем как голову
        this->head = node;
        return;
    }

    if (!p) { // если nullptr - вставка после последнего элемента списка
        position last = findLasT(); // последний элемент

        nodeList *node1; // создаем новый узел для вставки
        node1 = new nodeList(x.name,x.adress);
        last->next = node1; // теперь это последний
    }

    else {

        nodeList *node1; // создаем новый узел и копируем инфу из узла с позицией р
        node1 = new nodeList(p->obj.name, p->obj.adress);

        node1->next = p->next; // он продолжает указывать на следующий за ним
        p->obj = x;

        p->next = node1;
    }
}

list1::position list1::enD()
{
    return nullptr;
}

list1::position list1::locatE(object& x)
{
    position cur = head; // cur - позиция первого узла

    while (cur) {
        if (cur->obj == x)           // ЗДЕСЬ РАБОТАЕТ ПЕРЕГРУЗКА ==
            return cur;
        cur = cur->next;
    }

    return nullptr;
}

object& list1::retrievE(position p) // возвращает объект(имя и адрес) в позиции p
{
    if (!findPositioN(p))
        throw REsultIsUndefined(); // если не существует или p=end(L)

    return p->obj;
}

list1::position list1::nexT(position p)
{
    if (!findPositioN(p))
        throw REsultIsUndefined(); // если р не существует или р = end(L)

    return p->next;
}

list1::position list1::previouS(position p)
{
    position m = findPositioN(p); // предыдущий за p храним

    if (m == head || !m) // если первый или не существует такой позиции
        throw REsultIsUndefined();

    return m;
}

list1::position list1::DeletE(position p)
{
    position m = findPositioN(p); // сохраняем позицию перед р

    if (!m) // нет такой позиции
        return p;

    position temp = p->next; // сохраняем позицию после р

    if (p == head){ // если голова
        head = head->next;
        delete p;
        return temp; // возвращаем элемент после удаленного

    } if (p->next == nullptr){ // если последний элемент
        delete p;
        m->next = nullptr;
        return temp; // возвращаем элемент после удаленного

    } else { // если элемент не head и не last
        m->next = p->next;
        delete p;
        return temp; // возвращаем элемент после удаленного
    }
}

void list1::makeNulL()
{
    destrucT();
}

list1::position list1::firsT()
{
    return head;
}

void list1::printLisT()
{
    std::cout << std::endl;

    if (!head)
        throw REsultIsUndefined();

    for  (position i = head; i != nullptr; i = i->next)
    {
        std::cout << i->obj.name << " - " <<  i->obj.adress << std::endl;
    }
}

void list1::constructoR() {

}
