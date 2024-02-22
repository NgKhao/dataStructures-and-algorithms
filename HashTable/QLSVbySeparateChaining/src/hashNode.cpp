#include "hashNode.h"

hashNode::hashNode()
{
    //ctor
}

hashNode::hashNode(string fullName, string stuId, string stuEmail, string phoneNum)
{
    this->fullName = fullName;
    this->stuId = stuId;
    this->stuEmail = stuEmail;
    this->phoneNum = phoneNum;
    this->next = nullptr;
}
hashNode::~hashNode()
{
    //dtor
}
