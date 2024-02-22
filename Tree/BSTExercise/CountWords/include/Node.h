#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;

class Node
{
    public:
        Node();
        Node(string k);
        virtual ~Node();
        void setKey(string val){ key = val;}
        string getKey(){ return key;}
        void setCount(int cnt) {count = cnt; }
        int getCount(){ return count;}
        void setRight(Node *val){ right = val;}
        Node *getRight(){ return right;}
        void setLeft(Node *val){ left = val;}
        Node *getLeft(){ return left;}
    protected:

    private:
        string key;
        int count;
        Node *right;
        Node *left;
};

#endif // NODE_H
