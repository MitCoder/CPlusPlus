// A program to print all anagarms together
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

struct word
{
	char* str;
	int index;
};

struct copyArr
{
	struct word* array;
	int size;
};

int compChar(const void *a,const void*b)
{
	return *(char*)a - *(char*)b;
}
int compStr(const void *a, const void*b)
{
	struct word* a1 = (struct word *)a;
	struct word* b1 = (struct word *)b;

	return strcmp(a1->str,b1->str);
}
void printAnagramsTogether(char* wordArr[],int size)
{
	struct copyArr* copyArray = new copyArr;	
	copyArray->size = size;
	copyArray->array = (struct word*)malloc(size*sizeof(struct word*));//creating an array of words
    //	copyArray->array = new word[size]//creating an array of words


	// copy words from the given wordArr to copyArray
	for (int i = 0; i < size; i++)
	{
		copyArray->array[i].index = i;
		copyArray->array[i].str = (char*)malloc(strlen(wordArr[i] + 1));
		strcpy(copyArray->array[i].str, wordArr[i]);
		cout << " copying " << copyArray->array[i].str << copyArray->array[i].index << endl;
	}

    //sort by letters for each word
	for (int i = 0; i < size; ++i)
	{
		qsort(copyArray->array[i].str, strlen(copyArray->array[i].str), sizeof(char), compChar);
		cout << "sorting letters " << copyArray->array[i].str << copyArray->array[i].index << endl;
	}

    //sort the array.
	qsort(copyArray->array, size, sizeof(copyArray->array[0]), compStr);

	for (int i = 0; i < size; i++)
	{
		cout << " sorting words " << copyArray->array[i].str << copyArray->array[i].index << endl;
		 cout << wordArr[copyArray->array[i].index] << endl;
	}
	cin.get();


}
int main()
{
	char* wordArr[] = { "cat", "dog", "tac", "god", "act" };
	int size = sizeof(wordArr) / sizeof(wordArr[0]);
	printAnagramsTogether(wordArr, size);
	return 0;
}