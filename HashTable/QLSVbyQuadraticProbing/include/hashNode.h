#ifndef HASHNODE_H
#define HASHNODE_H
#include<string>
using namespace std;

class hashNode
{
    public:
        hashNode();
        hashNode(string fullName, string stuId, string stuEmail, string phoneNum);
        virtual ~hashNode();
        string getFullName(){ return fullName;}
        string getStudentID(){ return stuId; }
        string getStudentEmail(){ return stuEmail;}
        string getPhoneNumber(){ return phoneNum;}
    protected:

    private:
//        key: fullName, value: stuId, stuEmail, phoneNum
        string fullName;
        string stuId;
        string stuEmail;
        string phoneNum;
};

#endif // HASHNODE_H
