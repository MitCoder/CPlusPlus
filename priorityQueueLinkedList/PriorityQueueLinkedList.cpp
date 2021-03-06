/* Priority queue using a linked list. Elements are added and removed based on priority.
Priority queue can also be achieved using heap sort
*/
#include "stdafx.h"
#include <iostream>
#include "PriorityQueueLinkedList.h"
using namespace std;

PriorityQueueLinkedList::PriorityQueueLinkedList() :head(NULL), tail(NULL) {};

void PriorityQueueLinkedList::add(int data, int priority) {

	node *newNode = new node;
	newNode->data = data;
	newNode->priority = priority;

	if (head == NULL) {
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else {
		node *temp = new node;
		temp = tail;
		if (temp == tail && newNode->priority < temp->priority) {
			newNode->next = temp;
			tail = newNode;
		}
		else {
			while (temp->next != NULL && newNode->priority > temp->next->priority) {
				temp = temp->next;
			}
			if (head->priority < newNode->priority) {
				newNode->next = NULL;
				head->next = newNode;
				head = newNode;
			}
			else {
				newNode->next = temp->next;
				temp->next = newNode;

			}
		}

	}

}
void PriorityQueueLinkedList::deletePriorityElement() {
	node *del = new node;

	if (head != NULL) {
		del = tail;
		while (del->next != head) {

			del = del->next;
		}
		del->next = NULL;

	}
}
void PriorityQueueLinkedList::retrieve() {
	node *temp = new node;
	temp = tail;
	while (temp != NULL) {
		cout << temp->priority;
		temp = temp->next;
	}
}
int main()
{
	int count, option;
	PriorityQueueLinkedList *classPtr = new PriorityQueueLinkedList();
	do {
		cout << "Enter options" << endl;
		cout << "case 1: Enter elements in queue based linked list" << endl;
		cout << "case 2: Retrieve" << endl;
		cout << "case 3: Delete" << endl;

		cout << "case 4: Exit" << endl;

		cin >> option;

		switch (option) {

		case 1: cout << "enter total elements in queue based linked list" << endl;
			cin >> count;
			cout << "Enter elements" << endl;
			for (int i = 0; i < count; i++) {
				int data, priority;
				cout << "data"; cin >> data;
				cout << "priority"; cin >> priority;
				classPtr->add(data, priority);
			}
			break;
		case 2: cout << "Retrieving elements in queue based on priority" << endl;
			classPtr->retrieve();
			cout << "RRRR" << endl;
			break;
		case 3: cout << "Delete element in queue based on priority" << endl;
			classPtr->deletePriorityElement();
			break;

		}
	} while (option != 4);
}