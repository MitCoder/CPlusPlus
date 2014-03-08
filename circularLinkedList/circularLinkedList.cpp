//circular linked list cpp file
#include<iostream>
#include"circularLinkedList.h"
using namespace std;
circularClass::circularClass()
{
	head = NULL;
}
void circularClass::insert(int data)
{
	circularStruct *ptr = new circularStruct;

	if (head == NULL)
	{
		ptr->data = data;
		ptr->next = ptr;
		head = ptr;
	}
	else
	{
		circularStruct *temp = new circularStruct;
		ptr->data = data;
		ptr->next = head;
		head = ptr;
		ptr = ptr->next;
		while (ptr->next != head->next)
		{
			ptr = ptr->next;
			cout << ptr->data << "fff" << ptr->next->data;
		}
		ptr->next = head;
	}
}
void circularClass::deleteNode(int delNode)
{
	circularStruct *delPtr = new circularStruct;
	circularStruct *prevPtr = new circularStruct;

	prevPtr = head;
	delPtr = head->next;

	while (delPtr->data != delNode)
	{
		delPtr = delPtr->next;
		prevPtr = prevPtr->next;
	}
	if (delPtr != head)
	{
		prevPtr->next = delPtr->next;
	}
	else
	{
		prevPtr->next = delPtr->next;
		head = delPtr->next;
	}
	delete delPtr;
}
void circularClass::retrieve()
{
	circularStruct *ptr = new circularStruct;

	ptr = head;
	cout << "Retrieveing" << endl;
	while (ptr->next != head)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
	cout << ptr->data << endl;

}
int main()
{
	circularClass *classPtr = new circularClass();
	int option;
	do
	{
		cout << "1.Insert element" << endl;
		cout << "2.Delete element" << endl;
		cout << "3.Retrieve element" << endl;
		cout << "5. Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1: cout << "Enter data in list" << endl;
			int data;
			cin >> data;
			classPtr->insert(data);
			break;
		case 2: cout << "Enter delete data in list" << endl;
			int deldata;
			cin >> deldata;
			classPtr->deleteNode(deldata);
			break;
		case 3: cout << "Retrieve list" << endl;
			classPtr->retrieve();
			break;
		case 5: exit(1);

		}
	} while (option != 5);

}