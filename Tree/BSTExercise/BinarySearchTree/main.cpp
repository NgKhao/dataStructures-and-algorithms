    #include <iostream>
    #include "BST.h"
    using namespace std;

    int main()
    {
//        BST tree;
//        Node *n;
//        n = new Node(9);
//        tree.insertNodeRe(tree.getRoot(),9);
////        n = new Node(20);
//        tree.insertNodeRe(20);
////        n = new Node(17);
//        tree.insertNodeRe(17);
////        n = new Node(25);
//        tree.insertNodeRe(25);
////        n = new Node(12);
//        tree.insertNodeRe(12);
////        n = new Node(11);
//        tree.insertNodeRe(11);
////        n = new Node(13);
//        tree.insertNodeRe(13);
//        tree.travelNLR();
//        cout << endl;
//    tree.deleteNodeRE(9);
//    tree.travelNLR();



    BST *tree = new BST();
    Node *n;
    n = new Node(4);
    tree->insertNodeRE(n);
    n = new Node(2);
    tree->insertNodeRE(n);
    n = new Node(6);
    tree->insertNodeRE(n);
    n = new Node(1);
    tree->insertNodeRE(n);
//    n = new Node(3);
//    tree->insertNodeRE(n);
    n = new Node(5);
    tree->insertNodeRE(n);
    n = new Node(7);
    tree->insertNodeRE(n);
//    n = new Node(8);
//    tree->insertNodeRE(n);
//    n = new Node(9);
//    tree->insertNodeRE(n);
//    n = new Node(10);
//    tree->insertNodeRE(n);
//    n = new Node(25);
//    tree->insertNodeRE(n);
//    n = new Node(27);
//    tree->insertNodeRE(n);
    tree->travelLNR();
    cout << endl;
    tree->deleteNodeRE(new Node(4));
    tree->travelLNR();
//    cout << (tree->search_xRE(21) ? "YES\n" : "NO\n");
//    cout << tree->countSLPSoSanh;

//    cout << tree->sumNode(tree->getRoot());
//    cout << endl;
//    cout << tree->findMax(tree->getRoot()) << " " << tree->findMin(tree->getRoot());
//    cout << endl;
//    cout << tree->countNode(tree->getRoot());
//    cout << endl;
//    cout << tree->countNodeLeaf(tree->getRoot());



//    BST *tree = new BST();
//    Node *n;
//    n = new Node(11);
//    tree->insertNode(n);
//    n = new Node(7);
//    tree->insertNode(n);
//    n = new Node(15);
//    tree->insertNode(n);
//    n = new Node(4);
//    tree->insertNode(n);
//    n = new Node(9);
//    tree->insertNode(n);
//    n = new Node(12);
//    tree->insertNode(n);
//    n = new Node(4);
//    tree->insertNode(n);
//    n = new Node(1);
//    tree->insertNode(n);
//    n = new Node(15);
//    tree->insertNode(n);
//    tree->travelNLR();

    return 0;
}
