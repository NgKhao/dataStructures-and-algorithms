#include "hashNode.h"

hashNode::hashNode()
{
    //ctor
}

hashNode::hashNode(int key, string value)
{
    this->key = key;
    this->value = value;
    this->next = nullptr;
}
hashNode::~hashNode()
{
    //dtor
}
