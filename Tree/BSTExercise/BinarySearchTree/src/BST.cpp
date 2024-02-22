#include "BST.h"

BST::BST()
{
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
}

bool BST::insertNode(Node *n)
{
    Node *p = this->root;
    Node *T;
    if(root == nullptr)
    {
        root = n;
        return true;
    }
    while(p)
    {
        T = p;
        if(p->getKey() == n->getKey()) return false;
        else if(p->getKey() > n->getKey())
        {
            p = p->getLeft();
        }
        else
        {
            p = p->getRight();
        }
    }
    if(T->getKey() > n->getKey())
    {
        T->setLeft(n);
    }
    else if(T->getKey() < n->getKey())
    {
        T->setRight(n);
    }
    return true;
}

Node* BST::insertNodeRe(Node *r, Node *p)
{
    if(r == nullptr)
    {
        return p;
    }

//    so sánh rồi phải return  root
    if(r->getKey() > p->getKey())
    {
        r->setLeft(insertNodeRe(r->getLeft(), p));
//        insertNodeRe(r->getLeft(),p);
//        return insertNodeRe(r->getLeft(),p);
//  khong return ve can set lai de tao lien ket
    }
    else if(r->getKey() < p->getKey())
    {
        r->setRight(insertNodeRe(r->getRight(), p));
//        insertNodeRe(r->getRight(),p);
    }
    return r;
}


void BST::insertNodeRE(Node *p)
{
//    cập nhật con trỏ root sau khi chèn 1 node vào cây nhị phân
    setRoot(insertNodeRe(this->root, p));
}

void BST::NLR(Node *r)
{
    if(r)
    {
        cout << r->getKey() << " ";
        NLR(r->getLeft());
        NLR(r->getRight());
    }
}

void BST::LNR(Node *r)
{
    if(r)
    {
        LNR(r->getLeft());
        cout << r->getKey() << " ";
        LNR(r->getRight());
    }
}

void BST::LRN(Node *r)
{
    if(r)
    {
        LRN(r->getLeft());
        LRN(r->getRight());
        cout << r->getKey() << " ";
    }
}

void BST::travelNLR()
{
    NLR(this->root);
}

void BST::travelLNR()
{
    LNR(this->root);
}

void BST::travelLRN()
{
    LRN(this->root);
}

Node* BST::search_x(int k)
{
    if(this->root == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node *p = this->root;
        while(p != nullptr)
        {
            if(p->getKey() > k)
            {
                p = p->getLeft();
            }
            else if(p->getKey() < k)
            {
                p = p->getRight();
            }
            else
            {
                return p;
            }
        }
    }
}

int BST::countSLPSoSanh = 0;
Node* BST::search_xRe(Node *r, int val)
{
    if(r == nullptr || r->getKey() == val)
    {
        return nullptr;
    }
    else
    {
        ++countSLPSoSanh;
        if(r->getKey() > val)
        {
//            r->setLeft(search_xRe(r->getLeft(), val));
            return search_xRe(r->getLeft(), val);
        }
        else if(r->getKey() < val)
        {
//            r->setRight(search_xRe(r->getRight(), val));
            return search_xRe(r->getRight(), val);
        }
    }
}

Node* BST::search_xRE(int val)
{
    return search_xRe(this->root, val);
}
//void BST::deleteNode(Node* n){
//    Node* p=n;
//    if(p->Getleft()==nullptr&&n->Getright()==nullptr)
//        delete n;
//    else{
//        if(p->Getright()!=nullptr){
//            while(p->Getleft()!=nullptr)//
//                p=p->Getleft();
//            n->Setkey(p->Getkey());
//    //sinh vien code
//            delete p;
//        }else{
//            while(p->Getright()!=nullptr)//
//                 p=p->Getright();
//
//            n->Setkey(p->Getkey());
//    //sinh vien code
//            delete p;
//        }
//    }
//}


//Phần tử thay thế ptt :
//* Cách 1: là phần tử lớn nhất trong cây con bên trái p
//* Cách 2: là phần tử nhỏ nhất trong cây con bên phải p

//Node* BST::findNodeMin(Node *del, Node *curr)
//{
//    if(curr->getLeft() != nullptr)
//    {
//        curr->setLeft(findNodeMin(del, curr->getLeft()));
//        return curr;
//    }
//    else{
//        del->setKey(curr->getKey());
//        del = curr;
//        Node *cur = curr->getLeft();
//        delete del;
//
//    }
//}
Node* BST::deleteRe(Node *r, Node *p)
{
    if(r == nullptr) return nullptr;
    else if(r->getKey() > p->getKey())
    {
        r->setLeft(deleteRe(r->getLeft(), p));
    }
    else if(r->getKey() < p->getKey())
    {
        r->setRight(deleteRe(r->getRight(), p));
    }
    else
    {
        if(r->getLeft() == nullptr)
        {
            Node* tmp = r;
            r = r->getRight();
            delete tmp;        }
        else if(r->getRight() == nullptr)
        {
            Node* tmp = r;
            r = r->getLeft();
            delete tmp;        }
        else
        {
//                trai nhat cay con phai
            Node *tmp = new Node(findMin(r->getRight()));
            r->setKey(tmp->getKey());
            r->setRight(deleteRe(r->getRight(), tmp)); // tham so t2 la r hoac tmp van dung
            //vi chi can key chu ko can can node, key cua 2 node do = nhau
        }
    }
    return r;
}

void BST::deleteNodeRE(Node *p)
{
    setRoot(deleteRe(this->root, p));
}

int sum = 0;
int BST::sumNode(Node *r)
{
    if(r)
    {
        sum += r->getKey();
        sumNode(r->getLeft());
        sumNode(r->getRight());
    }
    return sum;
//    if(r == nullptr )
//        return 0;
//    return r->getKey() + sumNode(r->getLeft()) + sumNode(r->getRight());
}

int BST::findMax(Node *r)
{
    // dk tro toi right, vi neu tro toi chinh no vi ko the tra ve value gi co y nghia
    if(r->getRight() == nullptr)
        return r->getKey();
    return findMax(r->getRight());
}

int BST::findMin(Node *r)
{
    if(r->getLeft() == nullptr)
        return r->getKey();
    return findMin(r->getLeft());
}

int BST::countNode(Node *r)
{
    if(r == nullptr)
        return 0;
    return 1 + countNode(r->getLeft()) + countNode(r->getRight());
}

int BST::countNodeLeaf(Node *r)
{
    if(r == nullptr) return 0;
    else{
        if(r->getLeft() == nullptr && r->getRight() == nullptr)
            return 1;
        else return countNodeLeaf(r->getLeft()) + countNodeLeaf(r->getRight());
    }

}
