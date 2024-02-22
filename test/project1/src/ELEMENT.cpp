#include "ELEMENT.h"

ELEMENT::ELEMENT()
{
    //ctor
    this->data = 0;
    this->pointer=nullptr;
}

ELEMENT::ELEMENT(int d)
{
    //ctor
    this->data = d;
    this->pointer=nullptr;
}

void ELEMENT :: showdata()
{
    cout << this->data;
}

int ELEMENT :: getdata()
{
    return this->data;
}

void ELEMENT :: setdata(int d)
{

    data = d;
}

ELEMENT* ELEMENT :: getPointer()
{
    return this->pointer;
}

void ELEMENT :: setPointer(ELEMENT *p )
{
    pointer = p;
}
ELEMENT::~ELEMENT()
{
    //dtor
}
