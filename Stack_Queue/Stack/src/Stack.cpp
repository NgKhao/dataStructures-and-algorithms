#include "Stack.h"
#include "iostream"
using namespace std;
Stack::Stack()
{
    this->linkedlist = new LINKEDLIST();
}

Stack::~Stack()
{
    //dtor
}

bool Stack::isEmpty()
{
        if(this->linkedlist->Gethead() == nullptr) return true;
        return false;
}

// them ptu vao dau
void Stack::push(int val)
{
    this->linkedlist->InsertFirst(new ELEMENT(val));
}

// lay gtri ptu tren cung ra khoi ngan xep
int Stack::pop()
{
    int val = this->linkedlist->Gethead()->Getdata();
    this->linkedlist->DeleteFirst();
    return val;
}

// lay gia tri ptu tren cung ra khoi ngan xep
int Stack::top()
{
    return this->linkedlist->Gethead()->Getdata();
}

void Stack::addTail(int val)
{
    this->linkedlist->InsertTail(new ELEMENT(val));
}

int Stack::popTail()
{
    int p = this->linkedlist->Gettail()->Getdata();
    this->linkedlist->DeleteTail();
    return p;
}

void Stack::printStack()
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

// chuyen he 10 sang he 2, 8, 10
void Stack::chuyenHeCoSo(int coSoCanChuyen, int coSo10)
{
    while(coSo10 != 0)
    {
        int x = coSo10 % coSoCanChuyen;
        push(x);
        coSo10 /= coSoCanChuyen;
    }
}

void Stack::printStackHeCoSo()
{
    cout << "\nKET QUA: ";
    while(!isEmpty())
    {
        int x = pop();
        if(x < 10)
        {
            cout << x;
        }
        else
        {
            if(x == 10)
            {
                cout << 'A';
            }
            if(x == 11)
            {
                cout << 'B';
            }
            if(x == 12)
            {
                cout << 'c';
            }
            if(x == 13)
            {
                cout << 'D';
            }
            if(x == 14)
            {
                cout << 'E';
            }
            if(x == 15)
            {
                cout << 'F';
            }
        }

    }
}
