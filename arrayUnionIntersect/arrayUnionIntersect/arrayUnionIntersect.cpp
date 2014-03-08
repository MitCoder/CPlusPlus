//find union and intersection of 2 unsorted arrays.array
#include<iostream>
using namespace std;

void unionArray(int arr1[], int arr2[], int num1,int num2);
void intersectArray(int arr1[], int arr2[], int num1, int num2);
bool check(int arr3[], int count,int findEle);
int hashFn(int element, int tableSize);

int main()
{
	int num1, num2;
	cout << "Enter no. of elements in array 1" << endl;
	cin >> num1;

	cout << "Enter no. of elements in array 2" << endl;
	cin >> num2;

	int *arr1=new int[num1];
	int *arr2=new int[num2];
	
	cout << "Enter elements in array 1" << endl;
	for (int i = 0; i < num1; i++)
	{
		cin >> arr1[i];
	}

	cout << "Enter elements in array 2" << endl;
	for (int i = 0; i < num2; i++)
	{
		cin >> arr2[i];
	}
	unionArray(arr1, arr2, num1, num2);
	intersectArray(arr1, arr2, num1, num2);
}
void unionArray(int arr1[], int arr2[], int num1, int num2)
{  //print all the elements
	cout << "Print union of all elements" << endl;
	int i = 0, j = 0;
	while (i < num1 || j < num2)
	{
		if (i < num1)
		{
			cout << arr1[i]<<" ";
			i++;
		}
		else
		{
			cout << arr2[j]<<" ";	
			j++;
		}
		
	}
	cout << endl;
	//print union but remove duplicates
	int *arr3 = new int[num1 + num2];
	int l = 0, m = 0, n = 0, count = 0;
	cout << "Print union without duplicates" << endl;

	while (m <= num1 && n <= num2)
	{
		if (m < num1 && !check(arr3, count, arr1[m]))
		{
			arr3[l] = arr1[m];
			l++;
			count++;
		}
		if (n < num2 && !check(arr3, count, arr2[n]))
		{
			arr3[l] = arr2[n];
			l++;
			count++;
		}
		m++;
		n++;
		
	}
	for (int i = 0; i < count; i++)
	{
		cout<<i<<" "<<count<<" "<<arr3[i]<<"   ";
			
	}
	cout << endl;
	cin.get();
}
bool check(int arr3[], int count,int findEle)
{
	if (count == 0)
		return false;
	else
	{
		for (int i = 0; i < count; i++)
		{
			if (arr3[i] == findEle)
				return true;
		}
		return false;
	}
}
void intersectArray(int arr1[], int arr2[], int num1, int num2)
{
	//finding intersection 2 two unsorted array using hash function
	//other way can be using BST based on larger array and then compare a smaller array with formed BST
	struct node
	{
		int data;
		node *next;
	};
	int tableSize = num1 < num2 ? num2 : num1;
	int minArrSize = num1 < num2 ? num1 : num2;

	struct node **hashNode = new struct node* [tableSize];
	for (int i = 0; i < tableSize; i++)
	{
		hashNode[i] = NULL;
	}
	for (int i = 0; i < tableSize; i++)
	{
		int index = hashFn(arr2[i], tableSize);
	//	cout << "index" << index << " " << arr2[i] << endl;
				
		if (hashNode[index] == NULL)
		{
			node *temp = new node;
			temp->data = arr2[i];
			temp->next = NULL;
			hashNode[index] = temp;
		}
		else
		{
			node *newNode = new node;
			newNode->data = arr2[i];
			newNode->next = NULL;
			node *tempHash = hashNode[index];
			while (tempHash->next != NULL)
			{
				tempHash = tempHash->next;
				
			}
			tempHash->next = newNode;
		}
 }
	cout << "Intersect " << endl;
	for (int i = 0; i < minArrSize; i++)
	{
		int index = hashFn(arr1[i], tableSize);
		node *tempPtr = new node;
		tempPtr = hashNode[index];
		
		if (tempPtr->data == arr1[i])
		{
			cout<< arr1[i]<<" ";
		}
		while (tempPtr->next != NULL)
		{
			tempPtr = tempPtr->next;
			if (tempPtr->data == arr1[i])
			{
				cout << "intersect" << arr1[i];
			}			
		}

	}	
	cin.get();
	
}
int hashFn(int element, int tableSize)
{
	int index = element%tableSize;
	return index;
}