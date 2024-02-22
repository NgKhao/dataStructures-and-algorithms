#include "Student.h"
#include<iostream>
using namespace std;
Student::Student()
{
    this->id = "0";
    this->fullName = "";
    this->gpa = 0.0;
}

Student::Student(string id, string fullName, double gpa)
{
    this->id = id;
    this->fullName = fullName;
    setGPA(gpa);
}
Student::~Student()
{
    //dtor
}

//muốn gọi đối tượng student bằng tt << thì phải thêm const vào nctt vài các getter method vì
//compiler mặc định nctt không được thay đổi trạng thái
ostream& operator<<(ostream &out, const Student &s)
{
    out << s.getId() << endl;
    out << s.getFullName() << endl;
    out << s.getGPA() << endl;
    return out;
}
