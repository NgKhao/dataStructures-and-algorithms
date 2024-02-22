#include "Node.h"

Node::Node()
{
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Employees e)
{
    this->employee = e;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
    //dtor
}

ostream& operator<<(ostream &out, Node &e)
{
    out << e.getEmployee().getId() << endl;
    out << e.getEmployee().getFullName() << endl;
    out << e.getEmployee().getPosition() << endl;
    out << e.getEmployee().getDateOfBirth() << endl;
    out << e.getEmployee().getStatics() << endl;
    out << e.getEmployee().getBasicSalary() << endl;
    out << e.getEmployee().getCoefficientSalary() << endl;
    out << e.getEmployee().getBasicSalary() * e.getEmployee().getCoefficientSalary() << endl << endl;
    return out;
}
