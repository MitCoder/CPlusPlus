#include<iostream>
#include"circularLinkedList.h"
using namespace std;
circularClass::circularClass()
{
	head = NULL;
}
void circularClass::insert(int data)
{
	circularStruct *circular = new circularStruct;
	circularStruct *temp = new circularStruct;
	temp = head;
	circular->data = data;
	circular->next = head;

	if (head != NULL) {
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = circular;
	}
	else {
		circular->next = circular;

	}
	head = circular;
}
void circularClass::deleteNode(int delNode)
{
	circularStruct *delPtr = new circularStruct;
	circularStruct *prevPtr = new circularStruct;
	delPtr = head->next;
	prevPtr = head;
	/*prevPtr = head;//this code will delete the del data in the circular list, but it will be an infinite loop if the del data isnt present in loop.
	delPtr = head->next;

	while (delPtr->data != delNode )
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
	delete delPtr;*/
	//the below code will exist out of loop if no del data is found in circular list
	while (delPtr != head)
	{
		if (delPtr->data == delNode)
		break;
		prevPtr = prevPtr->next;
		delPtr = delPtr->next;

	}
	if (delPtr != head)
	{
		prevPtr->next = delPtr->next;
		delete delPtr;
	}
	if (delPtr == head && delPtr->data == delNode)
	{
		cout << delPtr->data << prevPtr->data;
		prevPtr->next = delPtr->next;
		head = delPtr->next;
		delete delPtr;

	}


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