#include "Node.h"

Node::Node()
{
    this->key = ' ';
    this->count = 1;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(char k)
{
    this->key = k;
    this->count = 1;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
}
