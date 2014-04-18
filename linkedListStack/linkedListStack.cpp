/*
1. enqueue is a operation of insertion into queue
2. dequeue is a operation of deletion from queue
3. front is a operation which returns the first element in the queue ie head
4. peek is a operation which returns the last element in the queue ie tail
the timecomplexity should be a constant time ie O(1)
*/
#include<iostream>
#include "linkedListStack.h"
using namespace std;

stackLinkedList::stackLinkedList()
{
	stackLinkedList::head = NULL;
	stackLinkedList::tail = NULL;
}
//insert element into queue
void stackLinkedList::insert(int data)
{
	node *newNode = new node;
	if (head == NULL)
	{
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}
}
//delete from the top ie head of the stack
void stackLinkedList::deleteElement()
{
	if (head == NULL)
		cout << "Stack is empty" << endl;
	else
	{
		node *delPtr = new node;
		node *tempPtr = new node;
		delPtr = head;
		head = delPtr->next;
		cout << "delete" << delPtr->data << endl;
		delete delPtr;
	}
}
void stackLinkedList::top()
{
	if (head == NULL)
	{
		cout << "No data in stack" << endl;
		cin.get();
	}
	else
	{
		cout << "top data in stack----------" << head->data << endl;
		cin.get();
	}

}
void stackLinkedList::front()
{
	if (head == NULL)
	{
		cout << "No data in queue" << endl;
		cin.get();
	}
	else
	{
		cout << "bottom data in stack----------" << tail->data << endl;
		cin.get();
	}

}
void stackLinkedList::printStack()
{
	if (head == NULL || tail == NULL)
		cout << "stack is empty" << endl;
	else
	{
		node *printPtr = new node;
		printPtr = head;

		while (printPtr != NULL)
		{
			cout << printPtr->data << "  ";
			printPtr = printPtr->next;
		}

	}

}
int main()
{
	stackLinkedList *classPtr = new stackLinkedList();
	int option;

	do
	{
		cout << "Enter options" << endl;

		cout << "1. Insert element in stack" << endl;
		cout << "2. Find top of the element in stack" << endl;
		cout << "3. Find bottom of the element in stack" << endl;
		cout << "4. Delete element in the stack" << endl;
		cout << "5. Print queue" << endl;
		cout << "7. exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1: int data;
			cout << "Enter data in queue" << endl;
			cin >> data;
			classPtr->insert(data);
			break;
		case 2: classPtr->top();
			break;
		case 3: classPtr->front();
			break;
		case 4: classPtr->deleteElement();
			break;
		case 5: classPtr->printStack();
			break;
		case 7: exit(1);
		}
	} while (option != 7);

}