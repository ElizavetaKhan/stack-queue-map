#include "QueueList.h"

QueueList::QueueList()
{
    this->tail = nullptr;
}

QueueList::~QueueList()
{
    this->MAKENULL();
}

void QueueList::enqueue(Object& x) // двигаем tail
{
    Node *node; // создаем новый узел для того, чтобы положить в очередь
    node = new Node(x.data);

    if (!tail) { // если первый элемент списка
        tail = node;

    } else {
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
}

Object QueueList::dequeue() // удаляем tail.next
{
    if (tail->next == tail) { // если один элемент в списке
        Object* temp = &tail->obj;

        delete tail;
        tail = nullptr;
        return *temp;
    }

    Node* head = tail->next; //голова
    Object* heaD = &tail->next->obj; // значение головы

    tail->next = head->next;
    delete head;
    return *heaD;
}

Object QueueList::FRONT()
{
    return tail->next->obj;
}

bool QueueList::FULL()
{
    return false;
}

bool QueueList::EMPTY()
{
    return tail;
}

void QueueList::MAKENULL()
{
    if (!tail)
        return;

    Node* currentNode = tail->next;

    while (currentNode != tail) {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    delete currentNode;
    tail = nullptr;
}

void QueueList::PRINT()
{
    if (tail) {
        std::cout <<  std::endl;

        for (Node* i = tail->next; i != tail; i = i->next)
            std::cout << i->obj.data << "   ";
        std::cout << tail->obj.data;

        std::cout <<  std::endl;
    }
}
