#include "StackATD.h"

StackATD::StackATD ()
{
    ATD = constructor();
}

StackATD::~StackATD()
{
    this->MAKENULL();
}

void StackATD::PUSH(Object& x)
{
    ATD.insert(x, ATD.first());
}

Object StackATD::POP()
{
    Object& peaktemp = ATD.retrieve(ATD.first());
    ATD.Delete(ATD.first());

    return peaktemp;
}

Object StackATD::TOP()
{
    return ATD.retrieve(ATD.first());
}

bool StackATD::FULL()
{
    return false;
}

bool StackATD::EMPTY()
{
    return ATD.first() == ATD.end();
}

void StackATD::MAKENULL()
{
    return ATD.makeNull();
}

void StackATD::PRINT()
{
    ATD.printList();
}
