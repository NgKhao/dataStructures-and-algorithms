#include "Node.h"

Node::Node()
{
    this->key = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

Node::Node(int k)
{
    this->key = k;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}
Node::~Node()
{
    //dtor
}
