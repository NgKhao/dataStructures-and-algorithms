#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(char k);
        virtual ~Node();
        void setKey(char val){ key = val;}
        char getKey(){ return key;}
        void setCount(int cnt) {count = cnt; }
        int getCount(){ return count;}
        void setRight(Node *val){ right = val;}
        Node *getRight(){ return right;}
        void setLeft(Node *val){ left = val;}
        Node *getLeft(){ return left;}
    protected:

    private:
        char key;
        int count;
        Node *right;
        Node *left;
};

#endif // NODE_H
