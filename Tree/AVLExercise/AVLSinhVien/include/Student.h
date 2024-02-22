#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<stdexcept>
using namespace std;

class Student
{
    public:
        Student();
        Student(string id, string fullName, double gpa);
        virtual ~Student();
        void setId(string val){ id = val;}
        string getId() const {return id;}
        void setFullName(string name){ fullName = name;}
        string getFullName() const {return fullName;}
        void setGPA(double score)
        {
            if(score >= 0.0 && score <= 4.0)
                gpa = score;
            else
                throw invalid_argument("GPA is invalid !!!");
        }
        double getGPA() const { return gpa;}
        friend ostream& operator<<(ostream &out, const Student &s);

    protected:
    private:
        string id;
        string fullName;
        double gpa;
};

#endif // STUDENT_H
