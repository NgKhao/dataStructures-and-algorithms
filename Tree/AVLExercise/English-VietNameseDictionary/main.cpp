#include <iostream>
#include<vector>
#include<utility>
#include<fstream>
#include"Node.h"
#include"AVLDic.h"
using namespace std;

bool readFile(vector<pair<string, string>>&dics, string fileName) // tham chieu dia chi vao vector
{
    ifstream fileIn;
    fileIn.open(fileName);
    string key, meaning;
    if(!fileIn.is_open())
    {
        return false;
    }
    while(!fileIn.eof())
    {
        fileIn >> key;
        getline(fileIn, meaning);
        dics.push_back(make_pair(key, meaning));
    }
    fileIn.close();
    return true;
}

int main()
{
    AVLDic *tree = new AVLDic();
    vector<pair<string, string>> dics;
    cout << (readFile(dics, "input.txt") ? "Mo file thanh cong.\n" : "Mo file that bai !!!!\n") ;
    for(auto it = dics.begin(); it != dics.end(); it++)
    {
        tree->insertNode(it->first, it->second);
    }
    tree->preOrder(tree->getRoot());
//    tree->search_meaning("water");
    tree->deleteNode("book");
    tree->preOrder(tree->getRoot());
    return 0;
}
