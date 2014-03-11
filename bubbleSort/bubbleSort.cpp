//sort the array of characters using bubble sort
#include<iostream>
using namespace std;

void bubbleSort(int dimension, char * table[]);
//int (*compare)(const char*,const char*)=strcmp;

int main()
{
	char *table[] = { "def", "abc" };
	int dimension;
	dimension = sizeof(table) / sizeof(table[0]);

	bubbleSort(dimension, table);
	return 0;

}

void bubbleSort(int dimension, char * table[])
{
	/*for (int i = 0, j = i + 1; i<dimension, j<dimension; i++, j++)
	{
	if (strcmp(table[i], table[j]) >0)
	{
	char *temp = NULL;
	temp = table[j];
	table[j] = table[i];
	table[i] = temp;

	}

	}*/
	for (int k = 0; k < dimension; k++)
	{
	for (int i = 0; i <dimension - 1; i++)
	{

		if (*table[i] > *table[i + 1])
		{
			char* temp = table[i];
			table[i] = table[i + 1];
			table[i + 1] = temp;
		}
	}
}
	for (int i = 0; i<dimension; i++)
	{
		cout << table[i] << endl;
		cin.get();
	}

}
