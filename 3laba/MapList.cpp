#include "MapList.h"

MapList::MapList()
{
    this->head = nullptr;
}

MapList::~MapList()
{
    this->MAKENULL();
}

void MapList::MAKENULL()
{
    if (!head)
        return;

    Node* currentNode = head;

    while (currentNode) {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    head = nullptr;
}

void MapList::ASSIGN(char* d, char* r)
{
    if (!head) {
        Node* node;
        node = new Node(d, r); // первый узел определяем как голову
        this->head = node;
        return;
    }

    object* obj = new object(d,r);
    Node* element = findName(*obj);

    if (element)
    {
        strcpy(element->obj.adress,r); // новое значение r в узел i списка
        return;
    }

    Node* node;
    node = new Node(d, r);

    node->next = head; // добавили в голову новый элемент, если не нашли его
    head = node;
}

bool MapList::COMPUTE(char* d, char* r)
{
    object* obj = new object(d,r);
    Node* element = findName(*obj);

    if (element)
    {
        strcpy(r,element->obj.adress); // новое значение r в узел i списка
        return true;
    }

    return false;
}

void MapList::PRINT()
{
    std::cout << std::endl;

    if (!head)
        return;

    for  (Node* i = head; i != nullptr; i = i->next)
    {
        std::cout << i->obj.name << " - " <<  i->obj.adress << std::endl;
    }
}

MapList::Node *MapList::findName(object& obj)
{
    for (Node* i = head; i != nullptr; i = i->next) {
        if (i->obj == obj)           // ЗДЕСЬ РАБОТАЕТ ПЕРЕГРУЗКА ==
        {
            return i;
        }
    }

    return nullptr;
}

