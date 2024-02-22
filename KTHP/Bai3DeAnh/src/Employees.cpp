#include "Employees.h"

Employees::Employees()
{
    this->id = "";
    this->fullName = "";
    this->position = "";
    this->dateOfBirth = "";
    this->statics = "";
    this->coefficientSalary = 0.0;
    this->basicSalary = 0.0;
    this->income = 0.0;
}

Employees::Employees(string id, string fullName, string position, string dateOfBirth, string statics, int basicSalary, double coefficientSalary)
{
    this->id = id;
    this->fullName = fullName;
    this->position = position;
    this->dateOfBirth = dateOfBirth;
    this->statics = statics;
    this->coefficientSalary = coefficientSalary;
    this->basicSalary = basicSalary;
    this->income = basicSalary * coefficientSalary;
}

Employees::~Employees()
{
    //dtor
}

//ostream& operator<<(ostream &out, Employees &e)
//{
//    out << e.getId() << endl;
//    out << e.getFullName() << endl;
//    out << e.getPosition() << endl;
//    out << e.getDateOfBirth() << endl;
//    out << e.getStatics() << endl;
//    out << e.getBasicSalary() << endl;
//    out << e.getCoefficientSalary() << endl;
//    out << e.getBasicSalary() * e.getCoefficientSalary() << endl << endl;
//    return out;
//}
