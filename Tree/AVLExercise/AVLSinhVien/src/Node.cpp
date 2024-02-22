#include "Node.h"
#include<iostream>
using namespace std;
Node::Node()
{
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
//  student sẽ tự động khởi tạo khi ko khai báo
}

Node::Node(Student s)
{
    this->student = s;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}
Node::~Node()
{
    //dtor
}

//ostream& operator<<(ostream &out, Node &p)
//{
//    out << p.getStudent().getId() << endl;
//    out << p.getStudent().getFullName() << endl;
//    out << p.getStudent().getGPA() << endl;
//    return out;
//}
