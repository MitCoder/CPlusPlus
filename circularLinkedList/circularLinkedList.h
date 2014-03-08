#include<iostream>
using namespace std;
struct circularStruct
{
	int data;
	circularStruct* next;
};

class circularClass
{
public:
	circularClass();
	circularStruct* head;
	void insert(int data);
	void retrieve();
	void deleteNode(int data);

private:
	int size;

};