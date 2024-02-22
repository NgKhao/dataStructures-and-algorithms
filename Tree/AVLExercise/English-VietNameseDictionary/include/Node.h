#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;

class Node
{
    public:
        Node();
        Node(string k, string m);
        virtual ~Node();
        void setKey(string val){ key = val;}
        string getKey(){ return key;}
        void setMeaning(string val){ meaning = val;}
        string getMeaning(){ return meaning;}
        void setRight(Node *val){ right = val;}
        Node *getRight(){ return right;}
        void setLeft(Node *val){ left = val;}
        Node *getLeft(){ return left;}
        void setHeight(int val){ height = val;}
        int getHeight(){ return (this == nullptr) ? 0 : height;}

    protected:

    private:
        string key;
        string meaning;
        Node* left;
        Node* right;
        int height;
};

#endif // NODE_H
