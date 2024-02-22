#ifndef AVLDIC_H
#define AVLDIC_H
#include"Node.h"

class AVLDic
{
    public:
        AVLDic();
        virtual ~AVLDic();
        void setRoot(Node *val){ root = val;}
        Node* getRoot(){ return root;}
        int getBalance(Node* r);
        Node* leftRotation(Node *r);
        Node* rightRotation(Node *r);
        void insertNode(string key, string meaning);
        void preOrder(Node *r);
        Node *search_x(Node *r, string key);
        void search_meaning(string key);
        static int countSlPSoSanh;
        void deleteNode(string key);
        Node* findMin(Node *r);
    protected:

    private:
        Node* root;
        Node* insertNode(Node* r, string key, string meaning);
        Node* deleteNode(Node *r, string key);

};

#endif // AVLDIC_H
