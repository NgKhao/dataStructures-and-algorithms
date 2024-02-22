#ifndef LISTOFEMPLOYEE_H
#define LISTOFEMPLOYEE_H
#include"Node.h"
class ListOfEmployee
{
    public:
        ListOfEmployee();
        virtual ~ListOfEmployee();
        void setRoot(Node *r){ root = r;}
        Node* getRoot(){ return root;}
        void addAEmployee(Employees e);
        void travelLNR(Node *r);
        void deleteAEmployee(Employees e);
    protected:

    private:
        Node *root;
        Node* addAEmployee(Node *r, Employees e);
        Node* deleteAEmployee(Node *r, Employees e);

};

#endif // LISTOFEMPLOYEE_H
