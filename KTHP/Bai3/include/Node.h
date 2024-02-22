#ifndef NODE_H
#define NODE_H
#include"Student.h"

class Node
{
    public:
        Node();
        Node(Student st);
        virtual ~Node();
        Student getStudent(){ return st;}
        void setLeft(Node *l){ left = l;}
        Node* getLeft(){return left;}
        void setRight(Node *r){ right = r;}
        Node* getRight(){return right;}
//        friend ostream& operator<<(ostream &out, Node &e);
    protected:

    private:
        Student st;
        Node *left;
        Node *right;
};

#endif // NODE_H
