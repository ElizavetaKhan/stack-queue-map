#include "list.h"

list::list()
{
    this->head = nullptr;
}

list::~list()
{
    destruct();
}

void list::destruct()
{
    if (!this->head)
        return;

    Node1* currentNode = this->head;

    while (currentNode) {
        Node1* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    this->head = nullptr;
}

list::position list::findPosition(position p)
{
    if (p == this->head) // если голова
        return this->head;

    position t = this->head;
    position prev = this->head;

    while (t) {
        if (p == t)
            return prev;

        prev = t;
        t = t->next;
    }
    return nullptr;
}

list::position list::findLast()
{
    position temp = this->head;
    position prev;

    while (temp) {
        prev = temp;
        temp = temp->next;
    }

    return prev;
}

void list::insert(Object& x, position p)
{
    if (!this->head) { // если первый узел в списке
        Node1* node;
        node = new Node1(x.data);
        this->head = node;
        return;
    }

    if (!p) { // если nullptr - вставка после последнего элемента списка
        position last = findLast(); // последний элемент

        Node1 *node1; // создаем новый узел для вставки
        node1 = new Node1(x.data);
        last->next = node1; // теперь это последний
    }

    else {

        Node1 *node1; // создаем новый узел и копируем инфу из узла с позицией р
        node1 = new Node1(p->obj.data);

        node1->next = p->next; // он продолжает указывать на следующий за ним
        p->obj.data = x.data;

        p->next = node1;
    }
}

list::position list::end()
{
    return nullptr;
}

list::position list::locate(Object& x)
{
    position cur = this->head; // cur - позиция первого узла

    while (cur) {
        if (cur->obj.data == x.data)
            return cur;
        cur = cur->next;
    }

    return nullptr;
}

Object* list::retrieve(position p) // возвращает объект (имя и адрес) в позиции p
{
    if (!findPosition(p))
        throw resultIsUndefined(); // если не существует или p=end(L)

    return &p->obj;
}

list::position list::next(position p)
{
    if (!findPosition(p))
        throw resultIsUndefined(); // если р не существует или р = end(L)

    return p->next;
}

list::position list::previous(position p)
{
    position m = findPosition(p); // предыдущий за p храним

    if (p == this->head || !m) // если первый или не существует такой позиции
        throw resultIsUndefined();

    return m;
}

list::position list::Delete(position p)
{
    position m = findPosition(p); // сохраняем позицию перед р

    if (!m) // нет такой позиции
        return p;

    position temp = p->next; // сохраняем позицию после р

    if (p == this->head){ // если голова
        this->head = this->head->next;
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

void list::makeNull()
{
    destruct();
}

list::position list::first()
{
    return this->head;
}

void list::printList()
{
    std::cout << std::endl;

    if (!this->head)
        throw resultIsUndefined();

     for (position i = head; i != nullptr; i = i->next)
         std::cout << i->obj.data << "   ";

    std::cout << std::endl;
}

void list::constructor() {

}
