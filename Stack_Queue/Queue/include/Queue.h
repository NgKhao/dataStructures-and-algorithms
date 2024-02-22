#ifndef QUEUE_H
#define QUEUE_H
#include "LINKEDLIST.h"

class Queue
{
    public:
        Queue();
        virtual ~Queue();
        bool isEmpty();
        void enQueue(int);
        int deQueue();
        int frontQueue();
        // them ptu cuoi
        void addTail(int);
        // lay gia tri cuoi va xoa cuoi
        int popTail();
        void printQueue();
    protected:

    private:
        LINKEDLIST *linkedlist;
};

#endif // QUEUE_H
