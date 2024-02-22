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
        void insertNode(Student s);
        void preOrder(Node *r);
//        Node *search_x(Node *r, int key);
//        static int countSlPSoSanh;
    protected:

    private:
        Node* root;
        Node* insertNode(Node* r, Student s);

};

#endif // AVL_H
