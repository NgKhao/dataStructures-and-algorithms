#include "BST.h"
#include<iostream>
using namespace std;
BST::BST()
{
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
}

Node* BST::insertNodeRe(Node *r, Node *p)
{
    if(r == nullptr)
        return p;
    if(r->getKey().compare(p->getKey()) > 0)
        r->setLeft(insertNodeRe(r->getLeft(), p));
    else if(r->getKey().compare(p->getKey()) < 0)
        r->setRight(insertNodeRe(r->getRight(), p));
    else
        r->setCount(r->getCount() + 1);
    return r;
}

void BST::insertNodeRE(Node *p)
{
    setRoot(insertNodeRe(this->root, p));
}

void BST::LNR(Node *r)
{
    if(r != nullptr)
    {
        LNR(r->getLeft());
        cout << r->getKey() << " " << r->getCount() << endl;
        LNR(r->getRight());
    }
}

int BST::countBeInputWord(Node *r, Node *p)
{
    // neu duyet ht van ko co thi return 0
    if(r == nullptr )
        return 0;
    else
    {
        if(r->getKey().compare(p->getKey()) > 0)
            return countBeInputWord(r->getLeft(), p);
        else if(r->getKey().compare(p->getKey()) < 0)
            return countBeInputWord(r->getRight(), p);
        else return r->getCount();
    }
}
