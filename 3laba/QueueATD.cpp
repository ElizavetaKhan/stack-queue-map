#include "QueueATD.h"

QueueATD::QueueATD()
{
    ATD = constructor2();
}

QueueATD::~QueueATD()
{
    this->MAKENULL();
}

void QueueATD::enqueue(Object& x)
{
    ATD.insert(x, ATD.end());
}

Object QueueATD::dequeue()
{
    Object& temp = ATD.retrieve(ATD.first());
    ATD.Delete(ATD.first());

    return temp;
}

Object QueueATD::FRONT()
{
    return ATD.retrieve(ATD.first());
}

bool QueueATD::FULL()
{
    return false;
}

bool QueueATD::EMPTY() const
{
    return ATD.first() == ATD.end();
}

void QueueATD::MAKENULL()
{
    ATD.makeNull();
}

void QueueATD::PRINT()
{
    ATD.printList();
}