/*
1. enqueue is a operation of insertion into queue
2. dequeue is a operation of deletion from queue
3. front is a operation which returns the first element in the queue ie head
4. peek is a operation which returns the last element in the queue ie tail
the timecomplexity should be a constant time ie O(1)
*/
#include<iostream>
#include "queueLinkedList.h"
using namespace std;

queueLinkedList::queueLinkedList()
{
	queueLinkedList::head = NULL;
	queueLinkedList::tail = NULL;
}
//insert element into queue
void queueLinkedList::enqueue(int data)
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
		newNode->next = tail;
		tail = newNode;
	}
}
//delete from the head of the queue
void queueLinkedList::dequeue()
{
	if (head == NULL)
		cout << "Queue is empty" << endl;
	else
	{
		node *delPtr = new node;
		node *tempPtr = new node;
		delPtr = head;
		tempPtr = tail;
		while (tempPtr->next != head)
		{
			tempPtr = tempPtr->next;

		}
		head = tempPtr;
		head->next = NULL;
		cout << "delete" << delPtr->data << endl;
		delete delPtr;
	}
}
void queueLinkedList::front()
{
	if (head == NULL)
	{
		cout << "No data in queue" << endl;
		cin.get();
	}
	else
	{
		cout << "front data in queue----------" << head->data << endl;
		cin.get();

	}

}
void queueLinkedList::rear()
{
	if (head == NULL)
	{
		cout << "No data in queue" << endl;
		cin.get();
	}
	else
	{
		cout << "tail data in queue----------" << tail->data << endl;
		cin.get();
	}

}
void queueLinkedList::printQueue()
{
	if (head == NULL || tail == NULL)
		cout << "queue is empty" << endl;
	else
	{
		node *printPtr = new node;
		printPtr = tail;

		while (printPtr != NULL)
		{
			cout << printPtr->data << "  ";
			printPtr = printPtr->next;
		}

	}

}
int main()
{
	queueLinkedList *classPtr = new queueLinkedList();
	int option;

	do
	{
		cout << "Enter options" << endl;

		cout << "1. Insert element in queue" << endl;
		cout << "2. Find front of the element in queue" << endl;
		cout << "3. Find rear of the element in queue" << endl;
		cout << "4. Delete element in the queue" << endl;
		cout << "5. Print queue" << endl;
		cout << "7. exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1: int data;
			cout << "Enter data in queue" << endl;
			cin >> data;
			classPtr->enqueue(data);
			break;
		case 2: classPtr->front();
			break;
		case 3: classPtr->rear();
			break;
		case 4: classPtr->dequeue();
			break;
		case 5: classPtr->printQueue();
			break;
		case 7: exit(1);
		}
	} while (option != 7);

}