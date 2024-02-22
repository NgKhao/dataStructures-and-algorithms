#include <iostream>
#include"Student.h"
#include"Node.h"
#include"AVL.h"
using namespace std;

int main()
{
    AVL *tree = new AVL();
    tree->insertNode(Student("01", "Nguyen A", 3.8));
    tree->insertNode(Student("02", "Pham B", 2.3));
    tree->insertNode(Student("03", "Bui C", 1.1));
    tree->preOrder(tree->getRoot());
    return 0;
}
