#include "StackList.h"

StackList::StackList()
{
    this->peak = nullptr;
}

StackList::~StackList()
{
    MAKENULL();
}

void StackList::PUSH(Object x)
{
    Node1 *node; // создаем новый узел для того, чтобы положить на вершину стека
    node = new Node1(x.data);

    if (!peak) { // если первый элемент списка
        peak = node;

    } else {
        node->next = peak;
        peak = node;
    }
}

Object StackList::POP()
{
    if (!peak->next) { // если один элемент в списке
        Object peaktemp = peak->obj;

        delete peak;
        peak = nullptr;
        return peaktemp;
    }

    Object peaktemp = peak->obj;
    Node1* next = peak->next;

    delete peak;
    peak = next;
    return peaktemp;
}

Object StackList::TOP()
{
    return peak->obj;
}

bool StackList::FULL()
{
    return false;
}

bool StackList::EMPTY()
{
    return peak == nullptr;
}

void StackList::MAKENULL()
{
    if (!peak)
        return;

    Node1* currentNode = peak;

    while (currentNode) {
        Node1* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    peak = nullptr;
}

void StackList::PRINT()
{
    if (peak) {
        std::cout <<  std::endl;

        for (Node1* i = peak; i != nullptr; i = i->next)
            std::cout << i->obj.data << "   ";

        std::cout << std::endl;
    }
}
