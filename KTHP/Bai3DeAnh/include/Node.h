#ifndef NODE_H
#define NODE_H
#include"Employees.h"

class Node
{
    public:
        Node();
        Node(Employees e);
        virtual ~Node();
        void setEmployee( Employees e){
            this->employee.setId(e.);
            this->position = "";
            this->dateOfBirth = "";
            this->statics = "";
            this->coefficientSalary = 0.0;
            this->basicSalary = 0.0;
            this->income = 0.0;}
        Employees getEmployee(){ return employee;}
        void setLeft(Node *l){ left = l;}
        Node* getLeft(){return left;}
        void setRight(Node *r){ right = r;}
        Node* getRight(){return right;}
        friend ostream& operator<<(ostream &out, Node &e);
    protected:

    private:
        Employees employee;
        Node *left;
        Node *right;
};

#endif // NODE_H
