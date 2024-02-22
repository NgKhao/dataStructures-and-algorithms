#include "ELEMENT.h"

ELEMENT::ELEMENT()
{
      this->data = 0;
      this->pointer = nullptr;
}

ELEMENT::ELEMENT(int data)
{
      this->data = data;
      this->pointer = nullptr;
}

ELEMENT::~ELEMENT()
{
      //dtor
}
