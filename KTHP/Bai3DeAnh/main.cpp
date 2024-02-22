#include <iostream>
#include"ListOfEmployee.h"
using namespace std;

int main()
{
    ListOfEmployee *le = new ListOfEmployee();
    le->addAEmployee(Employees("1", "Khao", "GD", "13/10/2004","con", 1000, 0.9));
    le->travelLNR(le->getRoot());
    return 0;
}
