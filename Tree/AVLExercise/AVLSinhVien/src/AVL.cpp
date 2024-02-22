#include "AVL.h"
#include<iostream>

using namespace std;
// so sanh chuoi
int compare(Student s1, Student s2)
{
    if(s1.getId() < s2.getId())
        return -1;
    else if(s1.getId() > s2.getId())
        return 1;
    else return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVL::AVL()
{
    this->root = nullptr;
}

AVL::~AVL()
{
    //dtor
}

int AVL::getBalance(Node *r)
{
    if(r == nullptr)
        return 0;
    return r->getLeft()->getHeight() - r->getRight()->getHeight();
}

//tham khao cach code tai https://www.youtube.com/watch?v=EArmT99aijk

Node* AVL::leftRotation(Node *r)
{

    Node* returnNode = r->getRight();
    r->setRight(returnNode->getLeft());
    returnNode->setLeft(r);

    // có cách xoay tương tự trên mạng

    r->setHeight(max(r->getLeft()->getHeight(), r->getLeft()->getHeight()) + 1);
    returnNode->setHeight(max(returnNode->getLeft()->getHeight(), returnNode->getRight()->getHeight()) + 1);

    return returnNode;
}

Node* AVL::rightRotation(Node *r)
{
    Node* returnNode = r->getLeft();
    r->setLeft(returnNode->getRight());
    returnNode->setRight(r);

    r->setHeight(max(r->getLeft()->getHeight(), r->getLeft()->getHeight()) + 1);
    returnNode->setHeight(max(returnNode->getLeft()->getHeight(), returnNode->getRight()->getHeight()) + 1);
    return returnNode;
}

Node* AVL::insertNode(Node *r, Student s)
{
    if(r == nullptr)
        return new Node(s);
    if(compare(s, r->getStudent()) < 0)
        r->setLeft(insertNode(r->getLeft(), s));
    else if(compare(s, r->getStudent()) > 0)
        r->setRight(insertNode(r->getRight(), s));
    else
        return r;

    r->setHeight(max(r->getLeft()->getHeight(), r->getRight()->getHeight()) + 1);

    int balance = getBalance(r);

    // LL case
    if(balance > 1 && compare(s, r->getLeft()->getStudent()) < 0)
    {
        return rightRotation(r);
    }
    //LR case
    if(balance > 1 && compare(s, r->getLeft()->getStudent()) > 0)
    {
        r->setLeft(leftRotation(r->getLeft())); // truyen node giua trong th LR vao ham
        return rightRotation(r);
    }
//    RR case
    if(balance < -1 && compare(s, r->getRight()->getStudent()) > 0)
    {
        return leftRotation(r);
    }
    if(balance < -1 && compare(s, r->getRight()->getStudent()) < 0)
    {
        r->setRight(rightRotation(r->getRight())); // truyen node giua trong th LR vao ham
        return leftRotation(r);
    }
    return r;
}

void AVL::insertNode(Student s)
{
    // tưởng tượng như root = insert (....);
    setRoot(insertNode(this->root, s));
}
void AVL::preOrder(Node *r)
{
    if(r != nullptr)
    {
        cout << (r->getStudent()); //<< r->getHeight() << endl;
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}
