#include "stdafx.h"
#include <iostream>
using namespace std;

struct node {
	int data;
	int priority;
	node *next;
};
class PriorityQueueLinkedList {

public:
	PriorityQueueLinkedList();
	node *head, *tail;
	void add(int data, int priority);
	void retrieve();
};
#pragma once
