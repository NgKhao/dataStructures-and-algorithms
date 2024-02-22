#ifndef STUDENT_H
#define STUDENT_H
#include<string>
using namespace std;

class Student
{
    public:
        Student();
        Student(string id, string fullName, string dateOfBirth, bool statics, string nump, string email, double dtb);
        virtual ~Student();
        string getId() const { return id;}
//        void setFullName(string f){ fullName = f;}
        string getFullName() const { return fullName;}
        string getDateOfBirth() const { return dateOfBirth;}
        bool getStatics() const{ return statics;}
        string getNump() const { return nump;}
        string getEmail() const {return email;}
        double getDtb() const { return dtb;}
        friend ostream& operator<< (ostream &os, const Student &data);
    protected:

    private:
        string id;
        string fullName;
        string dateOfBirth;
        bool statics; // tình trạng
        string nump;
        string email;
        double dtb;
};

#endif // STUDENT_H
