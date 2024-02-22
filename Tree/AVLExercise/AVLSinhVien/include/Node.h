#ifndef NODE_H
#define NODE_H
#include"Student.h"

class Node
{
    public:
        Node();
        Node(Student s);
        virtual ~Node();
//        void setStudent(int val){ student = val;}
        Student getStudent() { return student;}
        void setRight(Node *val){ right = val;}
        Node *getRight(){ return right;}
        void setLeft(Node *val){ left = val;}
        Node *getLeft(){ return left;}
        void setHeight(int val){ height = val;}
        int getHeight(){ return (this == nullptr) ? 0 : height;}
//        friend ostream& operator<<(ostream &out, Node &p);

    protected:

    private:
        Student student;
        Node* left;
        Node* right;
        int height;
};

#endif // NODE_H
