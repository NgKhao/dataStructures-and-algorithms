#ifndef AVL_H
#define AVL_H
#include"Node.h"

class AVL
{
    public:
        AVL();
        virtual ~AVL();
        void setRoot(Node *val){ root = val;}
        Node* getRoot(){ return root;}
        int getBalance(Node* r);
        Node* leftRotation(Node *r);
        Node* rightRotation(Node *r);
        void insertNode(int key);
        void inOrder(Node *r);
        Node *search_x(Node *r, int key);
        static int countSlPSoSanh;
        void deleteNode(int key);
        int findMin(Node *r);
    protected:

    private:
        Node* root;
        Node* insertNode(Node* r, int key);
        Node* deleteNode(Node *r, int key);

};

#endif // AVL_H
