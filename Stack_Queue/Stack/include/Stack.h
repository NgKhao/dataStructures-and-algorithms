#ifndef STACK_H
#define STACK_H
#include "LINKEDLIST.h"

class Stack
{
    public:
        Stack();
        virtual ~Stack();
        bool isEmpty();
        void push(int);
        int pop();
        int top();
        // them ptu cuoi
        void addTail(int);
        // lay gia tri cuoi va xoa cuoi
        int popTail();
        void printStack();
        // chuyen he 10 sang he 2, 8, 10
        void chuyenHeCoSo(int, int);
        void printStackHeCoSo();
    protected:

    private:
        LINKEDLIST *linkedlist;
};

#endif // STACK_H
