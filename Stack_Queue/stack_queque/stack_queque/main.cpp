#include <iostream>
#include<Stack.h>
using namespace std;

int main()
{

    Stack *s=new Stack();
    s->push(7);
    s->push(10);
    s->push(18);
    s->push(20);
    s->prinStack();
    s->pop();
    cout<<"\n";
    s->prinStack();

    return 0;
}
