#ifndef BST_H
#define BST_H
#include"Node.h"

class BST
{
    public:
        BST();
        virtual ~BST();
        void setRoot(Node *r){ root = r;}
        Node* getRoot(){ return root;}
        void travelLNR(Node *r);
        void insert(Student s);
        Node* search_x(Student s);
        void inputStudentList();
    protected:

    private:
        Node *root;
        Node* insert(Node *r, Student s);
        Node* search_x(Node *r, Student s);
};

#endif // BST_H
