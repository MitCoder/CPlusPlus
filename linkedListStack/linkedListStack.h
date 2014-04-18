#include<iostream>
using namespace std;

struct node
{
	node *next;

	int data;
};

class stackLinkedList
{

public:
	stackLinkedList();
	void insert(int data);
	void deleteElement();
	void top();
	void front();
	void printStack();
	node *head;
	node *tail;
};