/*Binary search is done in for elements which are sorted in order in.Searching takes  O(logn) whereas inserting takes O(1). 
Binary search is usually for used for a sorted array and search takes 0(log n). Binary search is not recommended for linked list since linked list doesnt provide random access.*/
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
	void retrieveList(node* list);
	int count(node* list);
	int search(int len, int itemFind);
	node* mergeSort(node* start, int size);
	node *merge(node *first, node *second, int size1, int size2);
	
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

void binarySearch::retrieveList(node* list)
{
	cout << "Printing list " << endl;//321 is changed to 123..head points to 1
	while (list != NULL)
	{
		cout << list->data << endl;
		list = list->next;
	}

}
int binarySearch::count(node* list)
{
	node *cntPtr = new node;
	int count = 0;
	for (cntPtr = list; cntPtr != NULL; cntPtr = cntPtr->next)
	{
		count++;
	}
	return count;
}
//mergesort time complexity worst case is O(nlogn).Space complexity is O(n)ie space is proportional to no. of elements.
node* binarySearch::mergeSort(node* start, int size)
{
	int mid;
	node* first = new node;
	node* second = new node;

	if (size>1)
	{
		mid = size / 2;
		int count = mid;
		node *middle = new node;
		middle = start;
		while (count)
		{
			middle = middle->next;
			count--;
		}
		first = mergeSort(start, mid);
		second = mergeSort(middle, size - mid);
		return merge(first, second, mid, size - mid);

	}
	else
		return start;
}
node* binarySearch::merge(node *first, node *second, int size1, int size2)
{
	node *result = new node;
	result = NULL;
	if (size1 == 0)
		return second;
	if (size2 == 0)
		return first;
	if (first->data < second->data || first->data == second->data)
	{
		result = first;
		first->next = merge(first->next, second, size1 - 1, size2);
		return first;
	}
	else
	{
		result = second;
		second->next = merge(first, second->next, size1, size2 - 1);
		return second;
	}
	
}
int binarySearch::search(int count, int findItem)
{
	node *midPtr = new node;
	int mid, low, high;
	high = count - 1;
	low = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		midPtr = binarySearch::head;

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
			high = mid - 1;
		}
		else
		{
			low = mid+1;
		}
	}

}
int main()
{
	binarySearch *classPtr = new binarySearch();
	int items, len, eleSearch;
	node *temp;
	cout << "Enter how many items to be added in linked list" << endl;
	cin >> len;
	cout << "Add elements in sorted manner in linked list" << endl;
	for (int i = 0; i<len; i++)
	{
		cin >> items;
		classPtr->addNode(items);
	}

	int count = classPtr->count(classPtr->head);
	node *sortList = classPtr->mergeSort(classPtr->head, count);
	temp = sortList;
	classPtr->head = sortList;
	int Cnt = 0;
	while (Cnt != count - 1)
	{
		cout << temp->data << endl;
		temp = temp->next;
		Cnt++;
	}
	temp->next = NULL;
	cout << "afsdfsfadsf" << classPtr->head->data<<endl;
	classPtr->retrieveList(sortList);

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
