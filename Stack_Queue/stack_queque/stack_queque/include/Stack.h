#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

class Stack
{
    private: int nNum;
              LinkedList *linkedlist;
    public:
        Stack();
        virtual ~Stack();
        void push(int);
        int pop();
        void prinStack();
};
#endif // STACK_H
