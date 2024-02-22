#include "Node.h"
#include<iostream>
using namespace std;
Node::Node()
{
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Student st)
{
    this->st = st;
    this->left = nullptr;
    this->right = nullptr;
}


Node::~Node()
{
    //dtor
}

//ostream& operator<<(ostream &out, Node &e)
//{
//    out << e.getStudent().getId() << endl;
//    out << e.getStudent().getFullName() << endl;
//    out << e.getStudent().getDateOfBirth() << endl;
//    out << e.getStudent().getStatics() << endl;
//    out << e.getStudent().getNump() << endl;
//    out << e.getStudent().getEmail() << endl;
//    out << e.getStudent().getDtb() << endl;
//    return out;
//}
