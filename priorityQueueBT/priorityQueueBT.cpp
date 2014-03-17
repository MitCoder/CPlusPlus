/* priority queue using a heap through an array. Array represents a complete BT
*/
#include<iostream>

#include "priorityQueueBT.h"
using namespace std;

priorityQueue::priorityQueue()
{
	size = 0;
}
void priorityQueue::add(int item)
{
	
	arr[size] = item;
	int parent = (size) / 2;
	int current = size;
	while (current != 0 && (arr[current] < arr[parent]))
	{
		int temp = arr[parent];
		arr[parent] = arr[current];
		arr[current] = temp;
		current = parent;
		parent = (current) / 2;
	
	};
	size++;
};
void priorityQueue::deleteHeap()
{
	/*int i = 0;
	size--;
	arr[0] = arr[size];
	int left = 2 * i;
	int right = left + 1;
	int largeVal;
	while (left < size)
	{

		if (right < size && arr[right] < arr[left])
		{
			largeVal = right;

		}
		else
		{
			largeVal = left;
		};
		if (arr[largeVal] < arr[i])
		{
			int temp = arr[i];
			arr[i] = arr[largeVal];
			arr[largeVal] = temp;
			i = largeVal;
			left = (2 * i);
			right = left + 1;
		}
		else
		{
			break;
		}
	};*/
	size--;
	arr[0] = arr[size];
	int current = 1;
	int parent = current / 2;
	if ( arr[parent] > arr[current])
	{
		int temp = arr[parent];
		arr[parent] = arr[current];
		arr[current] = temp;
	//	current = parent;
	//	parent = (current) / 2;
		current++;
		parent = current / 2;
	}
	

	
cin.get();
}
int main()
{
	priorityQueue *classPtr = new priorityQueue();
	int heapSize;
	cout << "Enter the number of elements in heap"<<endl;
	cin >> heapSize;
	classPtr->arr[heapSize];

	cout << "Enter the elements in the heap" << endl;
	priorityQueue **queueArr = new priorityQueue*[heapSize];
	for (int i = 0; i < heapSize; i++)
	{
		priorityQueue *temp = new priorityQueue();
		int heapItem;
		cin >> temp->item;
		queueArr[i] = temp;
	}

	cout << "Items in the heap in unsorted" << endl;
	for (int i = 0; i < heapSize; i++)
	{
		cout << queueArr[i]->item<< endl;
	}
	//Sort the items in the heap
	for (int i = 0; i < heapSize; i++)
	{
		classPtr->add(queueArr[i]->item);
	}
	cout << "retrueve"<<endl;
	for (int i = 0; i < heapSize; i++)
	{
		cout << classPtr->arr[i] << " parent is " << classPtr->arr[i / 2] << "left" << classPtr->arr[2*i] << "right" << classPtr->arr[2*i+1] << endl;
		//cout << classPtr->arr[i] << endl;

		cin.get();
	}
	
	cout << "Delete" << endl;
	classPtr->deleteHeap();
	cout << "delet retireve" << endl;
	for (int i = 0; i < heapSize; i++)
	{
		cout << classPtr->arr[i] << " parent is " << classPtr->arr[i / 2] << "left" << classPtr->arr[2 * i] << "right" << classPtr->arr[2 * i + 1] << endl;
		//cout << classPtr->arr[i] << endl;

		cin.get();
	}
	return 0;

}