#include <iostream>
#include "HashNode.h"


//Create the hash table, populate with hashnodes all set to null
hashTable::hashTable()
{
	table = new hashNode * [TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}
}

hashTable::~hashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)

		if (table[i] != NULL)

			delete table[i];

	delete[] table;
}



int hashTable::hash(string name)
{
	int hash = 0;
	int bucket;

	for (int i = 0; i < name.length(); i++)
	{
		hash = hash + (int)name[i];
		cout << "hash =	" << hash << endl;
	}

	bucket = hash % TABLE_SIZE;

	return bucket;
}

void hashTable::add(string name, string type)
{
	hashNode *temp = new hashNode(name, type);
	int location = hash(name);
	if (table[location] == NULL)
	{
		table[location] = temp;
	}
	else
	{
		temp->next = table[location];
		table[location] = temp;
	}

}

void hashTable::printTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != NULL)
		{
			cout << "name = " << table[i]->name << " "
				<< "type = " << table[i]->type << endl;
		}
	}

}
