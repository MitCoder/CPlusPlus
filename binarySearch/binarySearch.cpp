//binary search is done in for elements which are sorted in order in  O(logn)
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
class binarySearch
{
public:
	void addNode(int item);
	void printList();
	int search(int len, int itemFind);
	binarySearch();
	node *head;
	node *tail;
};
binarySearch::binarySearch()
{
	binarySearch::head = NULL;
	binarySearch::tail = NULL;

}

void binarySearch::addNode(int item)
{
	node *newNode = new node;
	if (head == NULL)
	{
		newNode->data = item;
		newNode->next = head;
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->data = item;
		newNode->next = head;
		head = newNode;
	}
}
void binarySearch::printList()
{
	node *ptr = new node;
	ptr = head;

	cout << "Printing list " << endl;//321 is changed to 123..head points to 1
	while (ptr != NULL)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}

}
int binarySearch::search(int count, int findItem)
{
	node *midPtr = new node;
	//	node *midPtr=new node;
	int mid, low, high;
	high = count - 1;
	low = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		midPtr = head;

		for (int i = 0; i<mid; i++)
		{
			midPtr = midPtr->next;
		}

		if (midPtr->data == findItem)
		{
			return midPtr->data;

		}

		if (findItem < midPtr->data)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

}
int main()
{
	binarySearch *classPtr = new binarySearch();
	int items, len, eleSearch;
	cout << "Enter how many items to be added in linked list" << endl;
	cin >> len;
	cout << "Add elements in sorted manner in linked list" << endl;
	for (int i = 0; i<len; i++)
	{
		cin >> items;
		classPtr->addNode(items);
	}
	classPtr->printList();
	cout << "Enter element to search" << endl;
	cin >> eleSearch;
	int findItem = classPtr->search(len, eleSearch);

	if (findItem)
		cout << findItem << "Found element in the list" << endl;
	else
		cout << findItem << "Not found" << endl;
	cin.get();
	return 0;
}