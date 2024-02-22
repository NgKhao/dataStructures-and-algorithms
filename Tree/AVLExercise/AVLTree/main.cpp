#include <iostream>
#include<vector>
#include<fstream>
#include"Node.h"
#include"AVL.h"
using namespace std;

bool readFile(vector<int>&numbers, string fileName) // tham chieu dia chi vao vector
{
    ifstream fileIn;
    fileIn.open(fileName);
    int num;
    if(!fileIn.is_open())
    {
        return false;
    }
    while(!fileIn.eof())
    {
        fileIn >> num;
        numbers.push_back(num);
    }
    fileIn.close();
    return true;

}
int main()
{
    AVL *tree = new AVL();
    vector<int> nums = {3,4,7,6,1,5};
//    cout << (readFile(nums, "input.txt") ? "Mo file thanh cong.\n" : "Mo file that bai !!!!\n") ;
    for(int i = 0 ; i < nums.size(); i++)
    {
//        tree->setRoot(tree->insertNode(tree->getRoot(),input[i]));
        tree->insertNode(nums[i]);
    }
    tree->inOrder(tree->getRoot());
    cout << endl;
    tree->deleteNode(3);
    tree->inOrder(tree->getRoot());
////    bai1
//    cout << (tree->search_x(tree->getRoot(), 21) ? "\nYES" : "\nNO");
//    cout << "\nSo phep so sanh tim duoc phan tu 21: " << tree->countSlPSoSanh;

    return 0;
}
