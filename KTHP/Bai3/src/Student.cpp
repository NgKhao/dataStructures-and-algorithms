#include "Student.h"
#include<iostream>
Student::Student()
{
    this->id = "";
    this->fullName = "";
    this->dateOfBirth = "";
    this->statics = 0;
    this->nump = "";
    this->email = "";
    this->dtb = 0.0;
}
Student::Student(string id, string fullName, string dateOfBirth, bool statics, string nump, string email, double dtb)
{
    //ctor
    this->id = id;
    this->fullName = fullName;
    this->dateOfBirth = dateOfBirth;
    this->statics = statics;
    this->nump = nump;
    this->email = email;
    this->dtb = dtb;
}

Student::~Student()
{
    //dtor
}

ostream& operator<< (ostream &os, const Student &data)
{
    os << data.getId() << endl;
    os << data.getFullName() << endl;
    os << data.getDateOfBirth() << endl;
    os << data.getStatics() << endl;
    os << data.getNump() << endl;
    os << data.getEmail() << endl;
    os << data.getDtb() << endl;
    return os;
}

