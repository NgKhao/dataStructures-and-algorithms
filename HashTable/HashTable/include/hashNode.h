#ifndef HASHNODE_H
#define HASHNODE_H
#include<string>
using namespace std;

class hashNode
{
    public:
        hashNode();
        hashNode(int key, string value);
        virtual ~hashNode();
        int getKey(){ return key;}
        string getValue(){ return value; }
        void setNext(hashNode *val){ next = val;}
        hashNode* getNext(){ return next; }

    protected:

    private:
        int key;
        string value;
        hashNode *next;


};

#endif // HASHNODE_H
