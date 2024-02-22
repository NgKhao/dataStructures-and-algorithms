#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "hashNode.h"

class hashTable
{
    public:
        hashTable(int sz);
        virtual ~hashTable();
        void insertNode(hashNode *p);
        bool deleteNode(string fullName);
        hashNode* searchNode(string fullName);
        void display();
    protected:

    private:
        hashNode **table; // dung de quan ly mang con tro hashNode
        int TABLE_SIZE; // size max of table
        int curr_size = 0; // current size of table;
        int hashFunc(string fullName);
};

#endif // HASHTABLE_H
