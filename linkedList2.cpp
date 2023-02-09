#include "linkedList2.h"
linkedList2::linkedList2()
{
    this->start = nullptr;
    this->End = nullptr;
}

linkedList2::~linkedList2()
{
    destruct();
}

void linkedList2::destruct()
{
    if (!this->start) // если пустой список
        return;

    nodeFor2link* currentNode = this->start;

    while (currentNode) {
        nodeFor2link* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    this->start = nullptr;
    this->End = nullptr;
}

bool linkedList2::findPosition(position p)
{
    position t = this->start;

    while (t) {
        if (p == t)
            return true;

        t = t->next;
    }

    return false;
}

void linkedList2::insert(Object& x, position p)
{
    if (!start) { // если первый узел в списке
        nodeFor2link* node;
        node = new nodeFor2link(x.data);
        this->start = node;
        this->End = node;
        return;
    }

    if (!findPosition(p)) { // если вставить после последнего - позиции р не существует
        position temp = this->End; // последний элемент

        nodeFor2link *node1; // создаем новый узел для вставки
        node1 = new nodeFor2link(x.data);

        temp->next = node1;
        node1->prev = temp;

        this->End = node1;

    } else if (p == this->End) { // если вставить в end
        position temp = this->End;

        nodeFor2link *node1; // создаем новый узел для вставки, помещаем туда end
        node1 = new nodeFor2link(this->End->obj.data);

        temp->obj.data = x.data;

        temp->next = node1;
        node1->prev = temp;

        this->End = node1; // переназначаем end

    } else if (p) { // позиция р есть в данном списке и это не end

        nodeFor2link *node1; // создаем новый узел для вставки
        node1 = new nodeFor2link(p->obj.data); // переносим данные из р в node1

        node1->next = p->next; // он продолжает указывать на следующий за ним
        p->obj.data = x.data;

        node1->prev = p;
        p->next = node1;
    }
}

linkedList2::position linkedList2::end()
{
    return nullptr;
}


linkedList2::position linkedList2::locate(Object& x)
{
    position cur = this->start; // cur - позиция первого узла

    while (cur) {
        if (cur->obj.data == x.data)
            return cur;
        cur = cur->next;
    }

    return nullptr;
}

Object* linkedList2::retrieve(position p)
{
    if (!findPosition(p))
        throw resultIsundefined(); // если не существует или p=end(L)

    return &p->obj;
}

linkedList2::position linkedList2::next(position p)
{
    if (!findPosition(p))
        throw resultIsundefined(); // если р не существует или р = end(L)

    return p->next;
}

linkedList2::position linkedList2::previous(position p)
{
    if (p != this->start && p)
        return p->prev;
    else
        throw resultIsundefined();
}

linkedList2::position linkedList2::Delete(position p)
{
    if (!findPosition(p)) // нет такой позиции
        return p;

    position next = p->next; // позиция после р
    position previous = p->prev; // позиция перед р

    if (p == start) { // если голова

        if (p == this->End) { // если совпадает с хвостом - то есть один элемент
            this->start = nullptr;
            this->End = nullptr;
            delete p;
            return nullptr;
        } else { // если просто голова, но не хвост
            this->start = this->start->next;
            this->start->prev = nullptr;
            delete p;
            return next; // возвращаем элемент следующий после удаленного
        }

    } if (p == this->End){ // если последний элемент
        previous->next = nullptr;
        this->End = previous;
        delete p;
        return next; // возвращаем элемент следующий после удаленного

    } else { // если элемент не start и не end
        previous->next = p->next;
        next->prev = previous;
        delete p;
        return next; // возвращаем элемент следующий после удаленного
    }
}

void linkedList2::makeNull()
{
    destruct();
}

linkedList2::position linkedList2::first()
{
    return this->start;
}

void linkedList2::printList()
{
    std::cout << std::endl;

    if (!this->start)
        throw resultIsundefined();

    for (position i = start; i != nullptr; i = i->next)
        std::cout << i->obj.data << "   ";

    std::cout << std::endl;
}

void linkedList2::constructor() {

}
