#include <iostream>
#include<ELEMENT.h>>


using namespace std;

int main()
{
    ELEMENT *p;
    p = new ELEMENT();
    p->setdata(100);
    p->showdata();

    cout << "\n";

    p = new ELEMENT(99);
    p->showdata();
    return 0;
}
