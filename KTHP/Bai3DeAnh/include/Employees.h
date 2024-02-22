#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include<iostream>
#include<string>
using namespace std;

class Employees
{
    public:
        Employees();
        Employees(string id, string fullName, string position, string dateOfBirth, string statics, int basicSalary, double coefficientSalary);
        virtual ~Employees();
        void setId(string i){ id = i;}
        string getId(){ return id;}
//        void setFullName(string f){ fullName = f;}
        string getFullName(){ return fullName;}
        string getPosition(){ return position;}
        string getDateOfBirth(){ return dateOfBirth;}
        string getStatics(){ return statics;}
        int getBasicSalary(){return basicSalary;}
        double getCoefficientSalary(){return coefficientSalary;}
        double getIncome(){ return getBasicSalary() * getCoefficientSalary();}
//        friend ostream& operator<<(ostream &out, Employees &e);

    protected:

    private:
        string id;
        string fullName;
        string position; // chức vụ
        string dateOfBirth;
        string statics; // tình trạng
        int basicSalary;
        double coefficientSalary; // hệ số lương
        double income; // thu nhập
};

#endif // EMPLOYEES_H
