#include "Queue.h"
#include "iostream"
using namespace std;
Queue::Queue()
{
    this->linkedlist = new LINKEDLIST();
}

Queue::~Queue()
{
    //dtor
}

bool Queue::isEmpty()
{
        if(this->linkedlist->Gethead() == nullptr) return true;
        return false;
}

// them ptu vao dau
void Queue::enQueue(int val)
{
    this->linkedlist->InsertTail(new ELEMENT(val));
}

// lay gtri ptu tren cung ra khoi ngan xep
int Queue::deQueue()
{
    int val = this->linkedlist->Gethead()->Getdata();
    this->linkedlist->DeleteFirst();
    return val;
}

// lay gia tri ptu tren cung ra khoi ngan xep
int Queue::frontQueue()
{
    return this->linkedlist->Gethead()->Getdata();
}

void Queue::addTail(int val)
{
    this->linkedlist->InsertTail(new ELEMENT(val));
}

int Queue::popTail()
{
    int p = this->linkedlist->Gettail()->Getdata();
    this->linkedlist->DeleteTail();
    return p;
}

void Queue::printQueue()
{
    if(isEmpty())
    {
        cout << "\nSTACK RONG, KHONG LAY DUOC PHAN TU" << endl;
    }
    else
    {
        this->linkedlist->Travel();
    }
}
