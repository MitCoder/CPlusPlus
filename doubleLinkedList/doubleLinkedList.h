#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};

class doubleLinkedList
{
public:
	doubleLinkedList();
	node* head;
	void insert(int data);
	void print();
	void reverse();
	void reversePrint();

	void deleteNode(int deldata);
	int countList();
};