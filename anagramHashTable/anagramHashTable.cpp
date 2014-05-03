#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<algorithm>
#include "anagramHashTable.h"
using namespace std;
using std::qsort;
anagramHastTable::anagramHastTable(){

}
int anagramHastTable::hashFn(char *key,int tableSize)
{
	int size = strlen(key);
	int hash = 0;
	for (int i = 0; i < size; i++)
	{
		hash = hash + (int)key[i];
	}
	hash = hash%tableSize;
	return hash;
    
}
 int anagramHastTable::compChar(const void* a, const void* b)
{
	return *(const char*)a - *(const char*)b;
}

void anagramHastTable::insert(char* wordArr[],const int size,node* hashNode)
{
//	copyArr *copyArray = new copyArr;
//	copyArray->array = new word[size];

	for (int i = 0; i < size; i++)
	{
		//copyArray->array[i].str = (char*)malloc(strlen(wordArr[i] + 1));
		//strcpy(copyArray->array[i].str, wordArr[i]);
	//	qsort(copyArray->array[i].str, strlen(copyArray->array[i].str), sizeof(char), anagramHastTable::compChar);
		int index = anagramHastTable::hashFn(wordArr[i],size);
		//cout << copyArray->array[i].str << "---" << index << endl;
		if (hashNode[index].name == "")
		{
			hashNode[index].name = wordArr[i];
			hashNode[index].next = NULL;
			cout << "null " << hashNode[index].name<<index << endl;

		}
		else
		{
			node *temp = new node;
			node *newNode = new node;
			newNode->name = wordArr[i];
			newNode->next = NULL;
			temp = &hashNode[index];
			while (temp->next != NULL)
			{
				temp = temp->next;
				cout << "not null--- " << temp->name << index << endl;

			}
			temp->next = newNode;
			cout << "not null " << temp->next->name << index << endl;

		}


	}
	for (int i = 0; i < size; i++)
	{
		node *temp = &hashNode[i];

		if (temp->next != NULL)
		{			
			while (temp->next != NULL)
			{
				cout << i <<temp->name << endl;
				temp = temp->next;

			}
			cout << i << temp->name << endl;
		}
	}

}

int main()
{
	anagramHastTable *classptr = new anagramHastTable();
	char* wordArr[] = { "cat", "dog", "tac", "god", "act" };

	int size = sizeof(wordArr) / sizeof(wordArr[0]);

	node *hashNode = new node[size];
 
	for (int i = 0; i < size; i++)
	{
		hashNode[i].name = "";
		hashNode[i].next = NULL;

	}
	classptr->insert(wordArr,size, hashNode);
	cin.get();

}
