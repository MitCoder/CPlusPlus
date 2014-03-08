#include<iostream>
using namespace std;

void  partitionStart(int* arr, int start, int end);
void  partitionEnd(int* arr, int start, int end);

int main()
{

	int elements;

	cout << "Enter the number of elements in an array" << endl;
	cin >> elements;

	int *arr;
	arr = new int[elements];

	cout << "Enter elements in an array" << endl;
	for (int i = 0; i<elements; i++)
	{
		cin >> arr[i];
	}
	partitionStart(arr, 0, (elements - 1));
//	partitionEnd(arr, 0, (elements - 1));

}
//pivot is the first element in the array
void partitionStart(int* arr, int start, int end)
{
	int pivot, pIndex;
	pivot = arr[start];
	pIndex = end;
	for (int i = start+1; i<=pIndex; i++)
	{
		if (arr[i] >= pivot && pIndex <= arr[i]) 
		{
			int temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;
			pIndex--;
		}
		
	}
	int temp = arr[start];
	arr[start] = arr[pIndex];
	arr[pIndex] = temp;

	cout << endl;
	cout << "Partitioning, where first element is the pivot" << endl;
	for (int i = start; i <= end; i++)
	{
		cout << arr[i] << endl;
		cin.get();
	}
	//return pIndex;
}
//pivot is the last element in the array
void partitionEnd(int* arr, int start, int end)
{
	int pivot, pIndex;
	pivot = arr[end];
	pIndex = start;

	for (int i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			int temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;
			pIndex = pIndex + 1;
		}

	}
	int temp = arr[end];
	arr[end] = arr[pIndex];
	arr[pIndex] = temp;

	cout << "Partitioning, where last element is the pivot" << endl;
	for (int i = start; i <= end; i++)
	{
		cout << arr[i] << endl;
		cin.get();
	}
}