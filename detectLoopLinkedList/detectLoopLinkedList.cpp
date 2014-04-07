#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;

};
node  *head=NULL;

void insert(node *list,int data);
void printlist(node *list);
void detectLoop(node *list);
void removeLoop(node *slow,node *head);

void insert(node *list, int data)
{
	node *newNode = new node;

    newNode->data = data;
    newNode->next = head;
    head = newNode;

}
void printlist(node *list)
{
	for (list = head; list != NULL;list = list->next)
	{
		cout << list->data << endl;
		cin.get();
	}
}
void detectLoop(node *list)
{
	node *fast = list;
	node *slow = list;

	while (fast != NULL && fast->next != NULL)
	{
//		cout << " slow " << slow->data << " fast " << fast->next->data << fast->next->next->data << endl;

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			cout << "loop"<<slow->data << endl;
			cin.get();

			removeLoop(slow,head);
		}
	}

}
void removeLoop(node *slow, node *head)
{
	node *ptr1=slow;
	node *ptr2=slow;
	int count=0;
	//how many items are there in loop
	while (ptr1->next != ptr2)
	{
		count++;
		ptr1 = ptr1->next;
	}
	//position both the pointers to head.
	ptr1 = head;
	ptr2 = head;
	for (int i = 0; i <= count;i++)
	{
		ptr2 = ptr2->next;
	}
	//place both the pointers in the same location.
	while (ptr2 != ptr1)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	//Once both the pointers meet at the same location, just traverse the ptr2 to the end of the list.This will let ptr2->next point to ptr1.
	ptr2 = ptr2->next;
	while (ptr2->next != ptr1)
	{
		ptr2 = ptr2->next;
	}
	ptr2->next = NULL;
	
/*	//below code also works
    node *fast = head;
	while (fast->next != slow->next)
	{
		fast = fast->next;
		slow = slow->next;
	}
	node *start = fast->next;
	fast = start;
	while (fast->next != start)
	{
		fast = fast->next;
	}
	fast->next = NULL;
	*/
}
int main()
{
	node *list = new node;
	insert(list, 10);
	insert(list, 4);
	insert(list, 15);
	insert(list, 20);
	insert(list, 50);
	head->next->next->next->next->next = head->next->next;
	detectLoop(head);
	printlist(head);

}