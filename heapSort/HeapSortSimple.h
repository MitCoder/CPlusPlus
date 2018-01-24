#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma once

class HeapSort {

public:
	HeapSort();
	void heapSort(int arr[]);
	void heapify(int arr[], int heapSize, int i);
	void retrieve();

	int heapSize;
	int arr[6];

};
#pragma once
