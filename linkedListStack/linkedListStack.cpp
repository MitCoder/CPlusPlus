/*
1. push is a operation of insertion into stack
2. pop is a operation of deletion from top of stack
3. front is a operation which returns the top element in the stack ie head
4. peek is a operation which returns the last element in the stack ie tail
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
		cout << "Printing stack data" << endl;
		while (printPtr != NULL)
		{
			cout << printPtr->data << "  ";
			printPtr = printPtr->next;
		}
		cout << endl;
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
		cout << "5. Print stack" << endl;
		cout << "7. exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1: int data;
			cout << "Enter data in stack" << endl;
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