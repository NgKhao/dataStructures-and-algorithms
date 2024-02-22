#include <iostream>
#include"hashNode.h"
#include"hashTable.h"
using namespace std;

int main()
{
    hashTable *ht = new hashTable();
    ht->insertNode(8, "pha");
    ht->insertNode(2, "le");
    ht->insertNode(1, "ngu");
    ht->insertNode(5, "tran");
    ht->display();
//    ht->deleteNode(1);
//    ht->display();
    int n; cin >> n;
    cout << ((ht->searchNode(n) == nullptr) ? "ko tim thay!!!" : ht->searchNode(n)->getValue());
    return 0;
}
