#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "hashNode.h"

class hashTable
{
    public:
        int const TABLE_SIZE = 3;
        hashTable();
        virtual ~hashTable();
        void insertNode(int key, string val);
        bool deleteNode(int key);
        hashNode* searchNode(int key);
        void display();
    protected:

    private:
        hashNode **table; // dung de quan ly mang con tro hashNode
        int hashFunc(int key);
};

#endif // HASHTABLE_H
