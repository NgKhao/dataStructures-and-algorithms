#include "hashTable.h"
#include <iostream>
#include<iomanip>
using namespace std;
hashTable::hashTable(int sz) : TABLE_SIZE(sz)
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

int hashTable::hashFunc(string fullName)
{
    int sum = 0;
    for(int i=0; i < fullName.size(); i++)
        sum += (int)tolower(fullName[i]);
    return sum % TABLE_SIZE;
}

void hashTable::insertNode(hashNode *p)
{
    int hashIndex = hashFunc(p->getFullName());
    hashNode *tmp = p;
    // insert first linked list
//    không cần kiểm tra dsach rỗng(head == nulll) như dslk vì hashtable không có tail
//    nên ko cần cập nhập tail trong điều kiện danh sách rỗng
    tmp->setNext(table[hashIndex]);
    table[hashIndex] = tmp;
}

bool hashTable::deleteNode(string fullName)
{
    int hashIndex = hashFunc(fullName);
    // Xoa ptu dau
    if(table[hashIndex]->getFullName().compare(fullName) == 0)
    {
        hashNode *p = table[hashIndex];
        table[hashIndex] = table[hashIndex]->getNext();
        delete p;
        return true;
    }

    // Xoa ptu giua va cuoi
    hashNode *prev = table[hashIndex];
    hashNode *curr = table[hashIndex]->getNext();
    while(curr != nullptr)
    {
        if(curr->getFullName().compare(fullName) == 0)
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

hashNode* hashTable::searchNode(string fullName)
{
    int hashIndex = hashFunc(fullName);
    hashNode* curr = table[hashIndex];
    while(curr != nullptr)
    {
        if(curr->getFullName().compare(fullName) == 0)
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
//        cout <<      "  +--------+--------+" << endl;
        cout << i << " |";
        hashNode* p = table[i];
        if (p == NULL ) {
            // NULL record, print empty
            cout << "[" << setw(6) << "" << " ]";// | " << setw(6) << "" << " |";
            }
        if(p != nullptr) {
            // Print the record from the table
            cout << "[ " << p->getFullName() << " | " << p->getStudentEmail() << ", " << p->getPhoneNumber() << ", " << p->getStudentID() << " ]";

            // Traverse and print the chain
            for (p = p->getNext(); p != nullptr ; p = p->getNext()) {
              cout << " --> " << "[ " << p->getFullName() << " | " << p->getStudentEmail() << ", " << p->getPhoneNumber() << ", " << p->getStudentID() << " ]";
            }
        }
        cout << endl;
    }
    cout << endl;
}
