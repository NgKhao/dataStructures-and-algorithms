#include "ListOfEmployee.h"
#include<iostream>
using namespace std;

int compare(Employees e1, Employees e2)
{
    if(e1.getId().compare(e2.getId()) == 0)
        return 0;
    else if(e1.getId().compare(e2.getId()) < 0)
        return -1;
    else
        return 1;
}
ListOfEmployee::ListOfEmployee()
{
    //ctor
    this->root = nullptr;
}

ListOfEmployee::~ListOfEmployee()
{
    //dtor
}

Node* ListOfEmployee::addAEmployee(Node *r, Employees e)
{
    if(r == nullptr)
        return new Node(e);
    else
    {
        if(compare(r->getEmployee(), e) > 0)
            return addAEmployee(r->getLeft(), e);
        else if(compare(r->getEmployee(), e) < 0)
            return addAEmployee(r->getRight(), e);
        else
            return r;
    }
}

void ListOfEmployee::addAEmployee(Employees e)
{
    setRoot(addAEmployee(getRoot(), e));
}

void ListOfEmployee::travelLNR(Node *r)
{
    if(r)
    {
        travelLNR(r->getLeft());
        cout <<*r;
        travelLNR(r->getRight());
    }
}

Node* ListOfEmployee::deleteAEmployee(Node *r, Employees e)
{
    if(r == nullptr) return nullptr;
    else
    {
        if(compare(r->getEmployee(), e) > 0)
        {
            r->setLeft(deleteRe(r->getLeft(), e));
        }
        else if(compare(r->getEmployee(), e) < 0)
        {
            r->setRight(deleteRe(r->getRight(), e));
        }
        else
        {
            if(r->getLeft() == nullptr)
            {
                Node* tmp = r->getRight();
                delete r;
                return tmp;
            }
            else if(r->getRight() == nullptr)
            {
                Node* tmp = r->getLeft();
                delete r;
                return tmp;
            }
            else
            {
//                trai nhat cay con phai
                Node *tmp = r->getRight();
                while(tmp->getLeft() != nullptr)
                    tmp = tmp->getLeft();
                r->setKey(tmp->getKey());
                r->setRight(deleteRe(r->getRight(), r->getEmployee())); // tham so t2 la r hoac tmp van dung
                //vi chi can key chu ko can can node, key cua 2 node do = nhau

//                phai nhat cay con trai
//                Node *tmp = r->getLeft();
//                while(tmp->getRight() != nullptr)
//                    tmp = tmp->getRight();
//                r->setKey(tmp->getKey());
//                r->setLeft(deleteRe(r->getLeft(), r));
            }
        }
    }
    return r;
}


