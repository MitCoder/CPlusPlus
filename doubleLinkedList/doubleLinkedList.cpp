/*
Doubly linked list
1.Insert
2.Reverse Print
3.Print
4.Delete a node
5.Count
*/
#include<iostream>
#include "doubleLinkedList.h"
using namespace std;

doubleLinkedList::doubleLinkedList()
{
	head = NULL;

}

void doubleLinkedList::insert(int newData)
{
	node *newNode = new node;
	if (head == NULL)
	{
		newNode->data = newData;
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;
	}
	else
	{
		newNode->data = newData;
		newNode->prev = NULL;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void doubleLinkedList::print()
{
	cout << "printed list is" << endl;
	for (node *ptr = head; ptr != NULL; ptr = ptr->next)
	{
		cout << ptr->data << endl;
	}
}
void doubleLinkedList::deleteNode(int delData)
{
	node *temp = new node;
	node *delPtr = new node;
	/*temp = head;
	while (temp->next->data != delData)
	{
		temp = temp->next;
	}
	delPtr = temp->next;

	if (delPtr->next != NULL)//not head node and the last node
	{
		temp->next = delPtr->next;
		temp->next->prev = temp;
	}
	if (delPtr->next == NULL)//last node
	{
		temp->next = delPtr->next;
	}
	delete delPtr;*/
	//the code below also resolves if the head->data is to be deleted
	node *delptr = new node;
	for (temp = head; temp != NULL; temp = temp->next)
	{
		
		if (temp->data == delData)
		{
			if (temp == head)
			{
				delptr = temp;
				temp->next->prev = NULL;
				head = temp->next;
			}
			else
			{
				delptr = temp;
				temp->prev->next = temp->next;
				temp->next = temp->prev;
			}
		}
		


	}
	delete delptr;

}
void doubleLinkedList::reversePrint()
{
	cout << "Printing reverse" << endl;
	node *ptr = new node;
	node *reversePtr = new node;
	ptr = head;
	while (ptr->next != NULL)
	{
	ptr = ptr->next;

	}
	for (reversePtr = ptr; reversePtr != NULL; reversePtr = reversePtr->prev)
	{
	cout << reversePtr->data << endl;
	}
}
void doubleLinkedList::reverse()
{
	node *Next,*Prev;
	Prev = NULL;
	cout << "list is reverse, head is changed now" << endl;
	node *ptr = new node;
	ptr = head;
	while (ptr != NULL)
	{
		Next = ptr->next;
		ptr->next = Prev;
		ptr->prev = Next;
		Prev = ptr;
		ptr = Next;

	}
	head = Prev;

}

int doubleLinkedList::countList()
{
	int count = 0;
	for (node *ptr = head; ptr != NULL; ptr = ptr->next)
	{
		count++;
	}
	return count;
}

int main()
{
	doubleLinkedList *listPtr = new doubleLinkedList();
	node *nodePtr = new node;
	int option, countData;
	while (1)
	{
		cout << "Choose options" << endl;
		cout << "1. Insert data" << endl;
		cout << "2. Print data" << endl;
		cout << "3. Print in Reverse" << endl;

		cout << "4. Count elements" << endl;
		cout << "5. Delete node" << endl;
		cout << "6. Reverse list" << endl;

		cout << "7. Quit" << endl;
		cin >> option;

		switch (option)
		{
		case 1:cout << "Enter data to insert" << endl;
			int data;
			cin >> data;
			listPtr->insert(data);
			break;
		case 2:	listPtr->print();
			break;
		case 3:	listPtr->reversePrint();
			break;
		case 4:	countData = listPtr->countList();
			cout << "Count of elements is " << countData << endl;
			break;
		case 5:	cout << "Enter data to delete" << endl;
			int deldata;
			cin >> deldata;
			listPtr->deleteNode(deldata);
			break;
		case 6:	listPtr->reverse();
			break;
		case 7: exit(1);

		}
	}

}