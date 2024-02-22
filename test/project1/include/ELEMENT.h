#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
using namespace std;

class ELEMENT
{
    public:
        ELEMENT();
        ELEMENT(int);
        void showdata();
        int getdata();
        void setdata(int);

        ELEMENT* getPointer();
        void setPointer(ELEMENT*);
        virtual ~ELEMENT();

    protected:

    private:
        int data;
        ELEMENT* pointer;

};


#endif // ELEMENT_H
