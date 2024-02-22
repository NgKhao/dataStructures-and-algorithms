#include "AVLDic.h"
#include<iostream>

using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLDic::AVLDic()
{
    this->root = nullptr;
}

AVLDic::~AVLDic()
{
    //dtor
}

int AVLDic::getBalance(Node *r)
{
    if(r == nullptr)
        return 0;
    return r->getLeft()->getHeight() - r->getRight()->getHeight();
}

//tham khao cach code tai https://www.youtube.com/watch?v=EArmT99aijk

Node* AVLDic::leftRotation(Node *r)
{

    Node* returnNode = r->getRight();
    r->setRight(returnNode->getLeft());
    returnNode->setLeft(r);

    // có cách xoay tương tự trên mạng

    r->setHeight(max(r->getLeft()->getHeight(), r->getLeft()->getHeight()) + 1);
    returnNode->setHeight(max(returnNode->getLeft()->getHeight(), returnNode->getRight()->getHeight()) + 1);

    return returnNode;
}

Node* AVLDic::rightRotation(Node *r)
{
    Node* returnNode = r->getLeft();
    r->setLeft(returnNode->getRight());
    returnNode->setRight(r);

    r->setHeight(max(r->getLeft()->getHeight(), r->getLeft()->getHeight()) + 1);
    returnNode->setHeight(max(returnNode->getLeft()->getHeight(), returnNode->getRight()->getHeight()) + 1);
    return returnNode;
}

Node* AVLDic::insertNode(Node *r, string key, string meaning)
{
    if(r == nullptr)
        return new Node(key, meaning);
    if(key < r->getKey())
        r->setLeft(insertNode(r->getLeft(), key, meaning));
    else if(key > r->getKey())
        r->setRight(insertNode(r->getRight(), key, meaning));
    else return r;

    r->setHeight(max(r->getLeft()->getHeight(), r->getRight()->getHeight()) + 1);

    int balance = getBalance(r);

    // LL case
    if(balance > 1 && key < r->getLeft()->getKey())
    {
        return rightRotation(r);
    }
    //LR case
    if(balance > 1 && key > r->getLeft()->getKey())
    {
        r->setLeft(leftRotation(r->getLeft())); // truyen node giua trong th LR vao ham
        return rightRotation(r);
    }
//    RR case
    if(balance < -1 && key > r->getRight()->getKey())
    {
        return leftRotation(r);
    }
    if(balance < -1 && key < r->getRight()->getKey())
    {
        r->setRight(rightRotation(r->getRight())); // truyen node giua trong th LR vao ham
        return leftRotation(r);
    }
    return r;
}

void AVLDic::insertNode(string key, string meaning)
{
    // tưởng tượng như root = insert (....);
    setRoot(insertNode(this->root, key, meaning));
}
void AVLDic::preOrder(Node *r)
{
    if(r != nullptr)
    {
        preOrder(r->getLeft());
        cout << r->getKey() << " " << r->getMeaning() << endl; //<< r->getHeight() << endl;
        preOrder(r->getRight());
    }
}

int AVLDic::countSlPSoSanh = 0;
Node* AVLDic::search_x(Node *r, string key)
{
    if(r == nullptr)
        return nullptr;
    ++countSlPSoSanh;
    if(key < r->getKey())
        return search_x(r->getLeft(), key);
    else if(key > r->getKey())
        return search_x(r->getRight(), key);
    else
        return r;
}

void AVLDic::search_meaning(string key)
{
    cout << search_x(this->root, key)->getKey() << " " << search_x(this->root, key)->getMeaning() << endl;
}

Node* AVLDic::deleteNode(Node *r, string key)
{
    if(r == nullptr)
        return nullptr;
    if(key < r->getKey())
        r->setLeft(deleteNode(r->getLeft(), key));
    else if(key > r->getKey())
        r->setRight(deleteNode(r->getRight(), key));
    else
    {
//        if(r->getLeft() == nullptr)
//        {
//            Node* tmp = r;
//            r = r->getRight();
//            delete tmp;        }
//        else if(r->getRight() == nullptr)
//        {
//            Node* tmp = r;
//            r = r->getLeft();
//            delete tmp;
//        }

//        cách hay
        if(r->getLeft() == nullptr || r->getRight() == nullptr)
        {
            Node *tmp = r->getLeft() ? r->getLeft() : r->getRight();

            if(tmp == nullptr)
            {
                tmp = r;
                r = nullptr;
            }
            else
                *r = *tmp;
            delete tmp;
        }
        else
        {
//                trai nhat cay con phai
            Node *tmp = findMin(r->getRight());
            r->setKey(tmp->getKey());
            r->setRight(deleteNode(r->getRight(), tmp->getKey())); // tham so t2 la r hoac tmp van dung
            //vi chi can key chu ko can can node, key cua 2 node do = nhau
        }
    }
//sau khi xóa r sẽ trỏ tới null, trong trường hợp này phải kiểm tra điều kiện và trả về cây ban đầu, trước khi
//thực hiện các thao tác khác nếu không cây sẽ tiếp tục quá trình cân bằng trong khi r đang null gây phát sinh lỗi
    if(r == nullptr)
        return r;
    // update height of the current node
    r->setHeight(max(r->getLeft()->getHeight(), r->getRight()->getHeight()) + 1);

    // get balance of the current node
    int balance = getBalance(r);

    // LL case
    if(balance > 1 && getBalance(r->getLeft()) >= 0)
        return rightRotation(r);

    // LR case
    if(balance > 1 && getBalance(r->getLeft()) < 0)
    {
        r->setLeft(leftRotation(r->getLeft()));
        return rightRotation(r);
    }

    // RR case
    if(balance < -1 && getBalance(r->getRight()) <= 0)
        return leftRotation(r);
    if(balance < -1 && getBalance(r->getRight()) > 0)
    {
        r->setRight(rightRotation(r->getRight()));
        return leftRotation(r);
    }
    return r;
}

void AVLDic::deleteNode(string key)
{
    setRoot(deleteNode(this->root, key));
}

Node* AVLDic::findMin(Node *r)
{
    if(r->getLeft() == nullptr)
        return r;
    return findMin(r->getLeft());
}
