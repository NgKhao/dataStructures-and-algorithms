#include <iostream>
#include "hashNode.h"


using namespace std;

int main()
{
	hashTable hash;
	hash.printTable();

	hash.add("a", "a");
	hash.add("ccc", "bnaad");
	hash.add("b", "bnaad");
    hash.add("k", "aa");


	hash.printTable();

	system("pause");

}
