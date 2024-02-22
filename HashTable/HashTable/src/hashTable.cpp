#include "hashTable.h"
#include <iostream>
#include<iomanip>
using namespace std;
hashTable::hashTable()
{
    //ctor
    table = new hashNode * [TABLE_SIZE];
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}

hashTable::~hashTable()
{
    //dtor
}

int hashTable::hashFunc(int key)
{
    return key % TABLE_SIZE;
}

void hashTable::insertNode(int key, string val)
{
    int index = hashFunc(key);
    hashNode *tmp = new hashNode(key, val);
    // insert first linked list
//    không cần kiểm tra dsach rỗng(head == nulll) như dslk vì hashtable không có tail
//    nên ko cần cập nhập tail trong điều kiện danh sách rỗng
    tmp->setNext(table[index]);
    table[index] = tmp;
}

bool hashTable::deleteNode(int key)
{
    int index = hashFunc(key);
    // Xoa ptu dau
    if(table[index]->getKey() == key)
    {
        hashNode *p = table[index];
        table[index] = table[index]->getNext();
        delete p;
        return true;
    }

    // Xoa ptu giua va cuoi
    hashNode *prev = table[index];
    hashNode *curr = table[index]->getNext();
    while(curr != nullptr)
    {
        if(curr->getKey() == key)
        {
            prev->setNext(curr->getNext());
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->getNext();
    }
    return false;
}

hashNode* hashTable::searchNode(int key)
{
    int index = hashFunc(key);
    hashNode* curr = table[index];
    while(curr != nullptr)
    {
        if(curr->getKey() == key)
        {
            return curr;
        }
        curr = curr->getNext();
    }
    return nullptr;
}
void hashTable::display()
{

    // Traverse the entire hash table
    for (int i=0; i < TABLE_SIZE; ++i) {
        cout <<      "  +--------+--------+" << endl;
        cout << i << " |";
        hashNode* p = table[i];
        if (p == NULL ) {
            // NULL record, print empty
            cout << " " << setw(6) << "" << " | " << setw(6) << "" << " |";

        } else {
            // Print the record from the table
            cout << " " << setw(6) << left << p->getKey() << " | " << setw(6) << right << p->getValue() << " |";

            // Traverse and print the chain
            for (p = p->getNext(); p != nullptr ; p = p->getNext()) {
              cout << " --> " << "[ " << p->getKey() << " | " << p->getValue() << " ]";
            }
        }
        cout << endl;
    }
    cout << "  +--------+--------+" << endl << endl;
}
