#include <iostream>
#include"BST.h"
#include"Node.h"
#include"Student.h"
using namespace std;

int main()
{
    BST *t = new BST();
//    t->insert(Student("1","0","0",0,"0","0",0));
//    t->insert(Student("2","0","0",0,"0","0",0));
//    t->insert(Student("3","0","0",0,"0","0",0));
    t->inputStudentList();
    t->travelLNR(t->getRoot());
    return 0;
}
