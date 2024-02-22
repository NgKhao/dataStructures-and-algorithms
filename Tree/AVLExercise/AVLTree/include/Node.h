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
        void setHeight(int val){ height = val;}
        int getHeight(){ return (this == nullptr) ? 0 : height;}

    protected:

    private:
        int key;
        Node* left;
        Node* right;
        int height;
};

#endif // NODE_H
