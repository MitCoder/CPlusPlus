/*Heap is a data structure where a array is visualized in a binary tree.The parent is always the largest then the children in max heap.
Sorting can be done easily in teh array rather than creating a new memory location.
To find the parent, divide the location by 2.
*/

#include "stdafx.h"
#include <iostream>
#include "HeapSortSimple.h";
using namespace std;

HeapSort::HeapSort() {};

void HeapSort::heapSort(int arr[]) {

	for (int i = heapSize / 2; i >= 0; i--) {
		heapify(arr, heapSize-1, i);
	}

}

//passing original array, heapsize and root.
void HeapSort::heapify(int arr[], int heapSize, int i) {

	cout << "heapSize " << heapSize << "i value " << i << endl;
	int largest = i;
	int left = 2 * i;
	int right = 2 * i+1;

	//left child is 2i, compare the root node aka arr[largest] with left child node aka arr[left] 
	if (largest< heapSize && arr[left] > arr[largest]) {
		largest = left;
	}

	//right child is 2i+1, compare the root node aka arr[largest] with right child node aka arr[right] 
	if (largest< heapSize && arr[right] > arr[largest]) {
		largest = right;
	}

	//swap the root node with higher right or left child node
	if (largest != i) {
		int temp = arr[largest]; 
		arr[largest] = arr[i];
		arr[i] = temp;
		heapify(arr, heapSize, largest);
	}
}

void HeapSort::retrieve() {

	for (int i = 0; i < heapSize; i++) {
		cout << arr[i] << " || ";
	}
}
int main()
{
	HeapSort *ptr = new HeapSort();
	int option = 0;

	do {
		cout << "Select options" << endl;
		cout << "case 1 :add items in heap" << endl;
		cout << "case 2: Max heapify" << endl;
		cout << "case 3: Delete" << endl;
		cout << "case 4 : Retrieve" << endl;
		cout << "case 5: Exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1:cout << "Number of elements in heap" << endl;
			cin >> ptr->heapSize;
			cout << "enter elements in heap" << endl;
			for (int i = 0; i < ptr->heapSize; i++) {
				int data;
				cin >> data;
				ptr->arr[i] = data;
			}
			break;
		case 2:cout << "HeapSort" << endl;
			ptr->heapSort(ptr->arr);
			break;

		case 4:cout << "Retrieve" << endl;
			ptr->retrieve();
			break;
		}
	} while (option != 5);
	return 0;
}

