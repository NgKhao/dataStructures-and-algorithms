#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(int k);
        virtual ~Node();
        void setKey(int val){ key = val;}
        int getKey(){ return key;}
        void setRight(Node *val){ right = val;}
        Node *getRight(){ return right;}
        void setLeft(Node *val){ left = val;}
        Node *getLeft(){ return left;}
        void setParent(Node *val){ parent = val;}
        Node *getParent(){ return parent;}
    protected:

    private:
        int key;
        Node *right;
        Node *left;
        Node *parent;
};

#endif // NODE_H
