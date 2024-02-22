#ifndef BST_H
#define BST_H
#include"Node.h"

class BST
{
    public:
        BST();
        virtual ~BST();
        void setRoot(Node *val){ root = val;}
        Node* getRoot(){ return root;}
        void insertNodeRE(Node *p);
        void LNR(Node *r);
        int countBeInputWord(Node *r, Node *p);
    protected:

    private:
        Node *root;
        Node* insertNodeRe(Node *r, Node *p);
};

#endif // BST_H
