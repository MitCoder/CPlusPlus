#include<iostream>
using namespace std;


class priorityQueue
{
	public:
		priorityQueue();
		void add(int item);
		void deleteHeap();
		void upheap(int item);
		int item;
		int size;//to initialize the size to 0 and then increment based on heapSize
		int arr[];//Store the elements of heap
};