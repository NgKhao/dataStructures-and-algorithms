#include <iostream>
#include"Node.h"
#include"BST.h"
using namespace std;

int main()
{
    BST *a = new BST();
    Node *n;
    string s = "hom nay toi hoc";
    for(int i=0; i < s.size(); i++)
    {
        n = new Node(s[i]);
        a->insertNodeRE(n);
    }
    a->LNR(a->getRoot());
    char x;
    cout << "\nNhap 1 ki tu can tim: "; cin >> x;
    cout << a->countBeInputChar(a->getRoot(), new Node(x));
    return 0;
}
