#include<iostream>
using namespace std;
struct linkedListStruct
{
	int data;
	linkedListStruct* Next;

};

class linkedListClass
{
public:
	linkedListClass();
	linkedListStruct* Head;
	linkedListStruct* Head2;
	linkedListStruct* Head3;


	void insert(int data);
	void insertSecond(int data);
	void appendList();
	void intersectionList();

	void  retrieve();
	void  retrieveList(linkedListStruct* list);
	void reverse(linkedListStruct* list);
	void countData();
	int count(linkedListStruct* list);
	void showDuplicate();
	void removeDuplicate();
	void insertElement(int data, int position);
	void sortList();
	void insertSort();
	void sortedListInsert(int newData);
	void alternateSplit();
	void shuffleMerge();
	void deleteLinkedList(linkedListStruct* list);
	linkedListStruct* mergeSort(linkedListStruct* start, int size);
	linkedListStruct* merge(linkedListStruct* first, linkedListStruct* second, int size1, int size2);

	//void insertSecond(int data);


private:
	int size;

};