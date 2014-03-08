#include<iostream>
using namespace std;

struct node
{
	node *next;

	int data;
};

class queueLinkedList
{

public:
	queueLinkedList();
	void enqueue(int data);
	void dequeue();
	void front();
	void rear();
	void printQueue();
	node *head;
	node *tail;
};