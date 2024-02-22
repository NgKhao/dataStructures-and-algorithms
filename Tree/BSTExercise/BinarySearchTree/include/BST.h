#ifndef BST_H
#define BST_H
#include "Node.h"
#include<iostream>
using namespace std;
class BST
{
    public:
        BST();
        virtual ~BST();
        void setRoot(Node *val){ root = val;}
        Node* getRoot(){ return root;}
        bool insertNode(Node *p);
        void insertNodeRE(Node *p);
        void travelNLR();
        void travelLNR();
        void travelLRN();
        Node* search_x(int k);
        Node* search_xRE(int val);
        static int countSLPSoSanh;
        void deleteNode(Node *n);
        void deleteNodeRE(Node *p);
        int sumNode(Node *r);
        int findMax(Node *r);
        int findMin(Node *r);
        int countNode(Node *r);
        int countNodeLeaf(Node *r);

    protected:

    private:
        Node *root;
        Node* insertNodeRe(Node *r, Node *p);
        void NLR(Node *r);
        void LNR(Node *r);
        void LRN(Node *r);
        Node* search_xRe(Node *r, int val);
        Node* deleteRe(Node *r, Node *p);
//        Node* findNodeMin(Node *del, Node *curr);
};

#endif // BST_H
