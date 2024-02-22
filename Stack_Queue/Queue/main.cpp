#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int x;
    Queue *s=new Queue();
    for(int i=0; i < 3; i++)
    {
        cout << "\nNhap phan tu "<< i+1<<": "; cin >> x;
    }
    for(int i=0; i<4; i++)
    {
        if(s->isEmpty())
        {
            cout << s->top();
            cout << "\nSTACK RONG, KHONG LAY DUOC PHAN TU" << endl;
        }
        else
        {
            cout << "\nGia tri lay ra: " << s->pop();
        }
    }
//    s->push(20);
//    s->printStack();
//    s->pop();
//    cout<<"\n";
//    s->printStack();

    return 0;
}
