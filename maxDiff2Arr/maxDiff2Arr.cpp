#include<iostream>
using namespace std;

int maxDiff(int arr[], int len)
{
	int maxDiff=arr[1]-arr[0] ;
	int minElement = arr[0];
	for (int i = 0; i < len; i++)
	{		
		if ((arr[i] - minElement)>maxDiff)
			maxDiff = arr[i] - minElement;
		if (arr[i] < minElement)
			minElement = arr[i];
	}
	return maxDiff;
}

int main()
{
	int arr[] = { 80, 2, 6, 3, 100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int diff = maxDiff(arr, len);
	cout<<len<<"----"<<diff;
	getchar();
	return 0;
}