#include "Node.h"

Node::Node()
{
    this->key = "";
    this->meaning = "";
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

Node::Node(string k, string m)
{
    this->key = k;
    this->meaning = m;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}
Node::~Node()
{
    //dtor
}
