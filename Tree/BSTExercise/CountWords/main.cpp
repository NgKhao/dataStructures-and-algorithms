#include <iostream>
#include<sstream>
#include"Node.h"
#include"BST.h"
using namespace std;

int main()
{
    BST *a = new BST();
    Node *n;
    string s = "hoc sinh di hoc mon sinh hoc ...";
    stringstream ss(s);
    string tmp;
    while(ss >> tmp)
    {
        n = new Node(tmp);
        a->insertNodeRE(n);
    }
    a->LNR(a->getRoot());
    return 0;
}
