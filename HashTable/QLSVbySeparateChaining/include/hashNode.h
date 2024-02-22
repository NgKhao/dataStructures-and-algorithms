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
        void setNext(hashNode *val){ next = val;}
        hashNode* getNext(){ return next; }

    protected:

    private:
//        key: fullName, value: stuId, stuEmail, phoneNum
        string fullName;
        string stuId;
        string stuEmail;
        string phoneNum;
        hashNode *next;


};

#endif // HASHNODE_H
