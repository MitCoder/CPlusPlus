// AnagramMappings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "AnagramMappings.h"
using namespace std;

HashTable::HashTable() {};

int HashTable::calculateHash(int key) {

	return key%5;

};

node* HashTable::insert(int key,int location, node *hashNode) {
	int hashValue = calculateHash(key);

	if (hashNode[hashValue].data ==0) {
		hashNode[hashValue].data = key;
		hashNode[hashValue].location = location;

		hashNode[hashValue].next = NULL;
	}
	else {
		node *newNode = new node;
		newNode->data = key;
		newNode->location = location;
		newNode->next = NULL;

		node *temp = &hashNode[hashValue];
		
		while (hashNode[hashValue].next!= NULL) {
			hashNode[hashValue] = *hashNode[hashValue].next;
		}
		hashNode[hashValue].next = newNode;
	}
	cout << "Hashvalue : " << hashValue << " Key " << key << " ";

	cout << "Insert : " << hashNode[hashValue].data<<" "<<endl;
	return hashNode;

}
void HashTable::anagramMappings(int A[], int B[],node *hashNode) {
	const int arrSize = 5;
	
	int mappings[arrSize];

	for (int i = 0; i < arrSize; i++) {

		hashNode= insert(B[i], i,hashNode);


	}

	for (int i = 0; i < arrSize; i++) {
		cout << "Mappings : " << hashNode[i].data << "i value " << i << " B element " << B[i] << endl;
		cout << "Mappings : " << hashNode[calculateHash(A[i])].data <<" location"<< hashNode[calculateHash(A[i])].location<< " i value" << i << " A element " << A[i] << endl;
		cout << "------------------------------------------------------------" << endl;

	}
	
}

void HashTable::retrieve(node *hashNode) {
	const int arrSize = 5;

	for (int i = 0; i < arrSize; i++) {
		cout << "KeyData : " << hashNode[i].data << " Location : " << hashNode[i].location << endl;
		while (hashNode[i].next != NULL) {
			cout << "KeyData : " << hashNode[i].data << " Location : " << hashNode[i].location << endl;
			hashNode[i] = *hashNode[i].next;

		}
	}
}

int main()
{
	int A[] = { 12, 28, 46, 32, 50 };
	int B[] = { 50, 12, 32, 46, 28 };
	int total = 5;

	node *hashNode = new node[total];

	for (int i = 0; i < total; i++) {
		hashNode[i].data = 0;
		hashNode[i].next = NULL;
	}
	
	HashTable *classPtr = new HashTable();
	classPtr->anagramMappings(A, B, hashNode);
	cout << "Retrieving" << endl;
	cout << "--------------------------------------------------------------------" << endl;

	classPtr->retrieve(hashNode);
	cin.get();
	return 0;
	
}

