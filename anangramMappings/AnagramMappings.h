

#include "stdafx.h"
#include <iostream>
using namespace std;
struct node {

	int data;
	int location;
	node *next;

};
class HashTable {

public:
	HashTable();
	void anagramMappings(int A[], int B[],node *newNode);
	node * insert(int key, int location,node *newNode);
	int calculateHash(int key);
	void retrieve(node *hashNode);
	int mappings[5];
};
