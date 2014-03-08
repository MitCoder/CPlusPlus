#include<iostream>
#define max 5
int top = -1;
int arr[max];

using namespace std;

void push(int data);
void pop();
void topFn();
int topRet();
void print();
void reverse(int arr[], int top, int len);

void print()
{
	cout << "Printing from top of stack stack" << top << endl;
	for (int i = top; i >= 0; i--)
	{
		cout << arr[i] << endl;
		cin.get();
	}
}
void reverse(int arr[], int len)
{

	int count = 0;
	while (count <= len)
	{
		int temp = arr[len - 1];
		arr[len - 1] = arr[count];
		arr[count] = temp;
		count++;
		len--;
	}

}
void push(int data)
{
	if (top == max - 1)
	{
		cout << "Overflow" << endl;
	}
	arr[++top] = data;
}
void pop()
{
	if (top == -1)
	{
		cout << "No element in stack" << endl;
	}
	arr[--top];
	//top--;
//	delete &arr[top];

}
void topFn()
{
	cout << "Top" << arr[top] << endl;
}

int main()
{
	int data;

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	print();
	pop();
	push(6);
	print();
	//topFn();

	int len = sizeof(arr) / sizeof(arr[0]);
	reverse(arr, len);
	print();
	push(12);
	print();

}