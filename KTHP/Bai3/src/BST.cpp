#include "BST.h"
#include<iostream>
using namespace std;

int compare(Student s1, Student s2)
{
    if(s1.getId().compare(s2.getId()) == 0)
        return 0;
    else if(s1.getId().compare(s2.getId()) < 0)
        return -1;
    else
        return 1;
}

BST::BST()
{
    //ctor
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
}

Node* BST::insert(Node *r, Student s)
{
    Node *n = new Node(s);
    if(r == nullptr)
        return n;


    if(compare(r->getStudent(),s) > 0){
        r->setLeft(insert(r->getLeft(), s));

    }
    else if(compare(r->getStudent(), s) < 0)
        r->setRight(insert(r->getRight(), s));

    return r;

}

void BST::insert(Student s)
{
    setRoot(insert(this->root, s));
//    cout << *root;
}

void BST::travelLNR(Node *r)
{
    if(r)
    {
        travelLNR(r->getLeft());
        cout <<r->getStudent();
        travelLNR(r->getRight());
    }
}

Node* BST::search_x(Node *r, Student s)
{
    if(r == nullptr)
    {
        return nullptr;
    }
    else
    {
        if(compare(r->getStudent(),s) > 0)
        {
            return search_x(r->getLeft(), s);
        }
        else if(compare(r->getStudent(),s) < 0)
        {
            return search_x(r->getRight(), s);
        }
        else return r;
    }
}

Node* BST::search_x(Student s)
{
    setRoot(search_x(getRoot(), s));
}

void BST::inputStudentList() {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string id;
            string name, birth, phone, email;
            bool status;
            double score;

            cout << "\nEnter information for Student " << i + 1 << ":" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin.ignore(); // Clear the buffer
            getline(cin, name);
            cout << "Birth Date (YYYY-MM-DD): ";
            cin >> birth;
            cout << "Status (1 for studying, 0 for finished): ";
            cin >> status;
            cout << "Phone Number: ";
            cin >> phone;
            cout << "Email Address: ";
            cin >> email;
            cout << "Average Score: ";
            cin >> score;

            insert(Student(id, name, birth, status, phone, email, score));
        }
    }
