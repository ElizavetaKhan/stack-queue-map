#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->start = nullptr;
    this->end = nullptr;
}

LinkedList::~LinkedList()
{
    destrucT();
}

void LinkedList::destrucT()
{
    if (!start) // если пустой список
        return;

    nodeList2* currentNode = start;

    while (currentNode) {
        nodeList2* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    start = nullptr;
    end = nullptr;
}

bool LinkedList::findPositioN(position p)
{
    position t = start;

    while (t) {
        if (p == t)
            return true;

        t = t->next;
    }

    return false;
}

void LinkedList::inserT(struct object& x, position p)
{
    if (!start) { // если первый узел в списке
        nodeList2* node;
        node = new nodeList2(x.name,x.adress);
        this->start = node;
        this->end = node;
        return;
    }

    if (!findPositioN(p)) { // если вставить после последнего - позиции р не существует
        position temp = end; // последний элемент

        nodeList2 *node1; // создаем новый узел для вставки
        node1 = new nodeList2(x.name,x.adress);

        temp->next = node1;
        node1->prev = temp;

        end = node1;

    } else if (p == end) { // если вставить в end
        position temp = end;

        nodeList2 *node1; // создаем новый узел для вставки, помещаем туда end
        node1 = new nodeList2(end->obj.name,end->obj.adress);

        temp->obj = x;

        temp->next = node1;
        node1->prev = temp;

        end = node1; // переназначаем end

    } else if (p) { // позиция р есть в данном списке и это не end

        nodeList2 *node1; // создаем новый узел для вставки
        node1 = new nodeList2(p->obj.name, p->obj.adress); // переносим данные из р в node1

        node1->next = p->next; // он продолжает указывать на следующий за ним
        p->obj = x;

        node1->prev = p;
        p->next = node1;
    }
}

LinkedList::position LinkedList::enD()
{
    return nullptr;
}


LinkedList::position LinkedList::locatE(object& x)
{
    position cur = start; // cur - позиция первого узла

    while (cur) {
        if (cur->obj == x)           // ЗДЕСЬ РАБОТАЕТ ПЕРЕГРУЗКА ==
            return cur;
        cur = cur->next;
    }

    return nullptr;
}

object& LinkedList::retrievE(position p)
{
    if (!findPositioN(p))
        throw resultIsundefiNED(); // если не существует или p=end(L)

    return p->obj;
}

LinkedList::position LinkedList::nexT(position p)
{
    if (!findPositioN(p))
        throw resultIsundefiNED(); // если р не существует или р = end(L)

    return p->next;
}

LinkedList::position LinkedList::previouS(position p)
{
    if (p != start && p)
        return p->prev;
    else
        throw resultIsundefiNED();

}

LinkedList::position LinkedList::DeletE(position p)
{
    if (!findPositioN(p)) // нет такой позиции
        return p;

    position next = p->next; // позиция после р
    position previous = p->prev; // позиция перед р

    if (p == start) { // если голова

        if (p == end) { // если совпадает с хвостом - то есть один элемент
            start = nullptr;
            end = nullptr;
            delete p;
            return nullptr;
        } else { // если просто голова, но не хвост
            start = start->next;
            start->prev = nullptr;
            delete p;
            return next; // возвращаем элемент следующий после удаленного
        }

    } if (p == end){ // если последний элемент
        previous->next = nullptr;
        end = previous;
        delete p;
        return next; // возвращаем элемент следующий после удаленного

    } else { // если элемент не start и не end
        previous->next = p->next;
        next->prev = previous;
        delete p;
        return next; // возвращаем элемент следующий после удаленного
    }
}

void LinkedList::makeNulL()
{
    destrucT();
}

LinkedList::position LinkedList::firsT()
{
    return start;
}

void LinkedList::printLisT()
{
    if (!start) // если в списке нет элементов
        throw resultIsundefiNED();
    std::cout << std::endl;

    for  (position i = start; i != nullptr; i = i->next)
    {
        std::cout << i->obj.name << " - " <<  i->obj.adress << std::endl;
    }
}

void LinkedList::constructoR() {

}
