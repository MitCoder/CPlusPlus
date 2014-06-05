#include<iostream>
#include "linkedlistChoices.h"
using namespace std;

linkedListClass::linkedListClass() :size(0), Head(NULL), Head2(NULL), Head3(NULL){};

void linkedListClass::insert(int data)
{
	linkedListStruct *curr = new linkedListStruct;
	curr->data = data;
	curr->Next = Head;
	Head = curr;

}
void linkedListClass::insertSecond(int data)
{
	linkedListStruct *curr = new linkedListStruct;

	curr->data = data;
	curr->Next = Head2;
	Head2 = curr;
}
void linkedListClass::appendList()
{
	linkedListStruct *curr = new linkedListStruct;
	linkedListStruct *currSec = new linkedListStruct;

	curr = Head;
	currSec = Head2;
	while (curr->Next != NULL)
	{
		curr = curr->Next;

	}
	curr->Next = currSec;
	currSec = NULL;

}
//time complexity is O(m*n)
void linkedListClass::intersectionList()
{
	linkedListStruct *first = new linkedListStruct;
	linkedListStruct *second = new linkedListStruct;
	linkedListStruct *result1 = new linkedListStruct;


	for (first = Head; first != NULL; first = first->Next)
	{
		for (second = Head2; second != NULL; second = second->Next)
		{

			if (first->data == second->data)
			{
				linkedListStruct *result = new linkedListStruct;
				result->data = first->data;
				result->Next = Head3;
				Head3 = result;
				cout << "head"<<Head3->data << endl;
			}
		}

	}
	cout << "Intersection results are" << endl;
	for (result1 = Head3; result1 != NULL; result1 = result1->Next)
	{

		cout <<"inster"<< result1->data<<endl;
	}

}
//time complexity O(m+n)
void linkedListClass::intersectionListComp()
{
	linkedListStruct *first = new linkedListStruct;
	linkedListStruct *second = new linkedListStruct;
	first = Head;
	second = Head2;

	int firstCount = linkedListClass::count(Head);
	int secondCount = linkedListClass::count(Head2);
	int differenceVal;
	if (firstCount > secondCount)
	{
		differenceVal = firstCount - secondCount;
		cout <<"difference "<< differenceVal<<endl;
	}
	else
	{
		differenceVal = secondCount - firstCount;
		cout << differenceVal;
	}

	for (int i = 0; i < differenceVal; i++)
	{
		if (first != NULL)
			first = first->Next;
	}

	while (first != NULL && second != NULL)
	{
		cout << first->data<<"while" << second->data<<endl;
		if (first->data == second->data)
		{
			cout << "intersect" << first->data << endl;
			break;
		}
		first = first->Next;
		second = second->Next;
	}

}
void linkedListClass::deleteElement(int data)
{
	linkedListStruct *curr = new linkedListStruct;
	linkedListStruct *prev = new linkedListStruct;

	linkedListStruct *delPtr = new linkedListStruct;
	curr = linkedListClass::Head;

	while (curr != NULL)
	{
		if (data == linkedListClass::Head->data)
		{
			delPtr = Head;
			Head = Head->Next;
		}
		else if (curr->data == data)
		{
			delPtr = curr;
			prev->Next = curr->Next;
		}
		prev = curr;
		curr = curr->Next;
	}
	delete delPtr;
}
void linkedListClass::insertElement(int data, int position)
{
	linkedListStruct *newElement = new linkedListStruct;
	linkedListStruct *curr = new linkedListStruct;
	linkedListStruct *prev = new linkedListStruct;

	newElement->data = data;
	int count = 0;
	for (curr = Head; curr != NULL; curr = curr->Next)
	{
		if (count == position)
		{
			/*newElement->Next = curr;
			prev->Next = newElement;
			return; //other way*/
			
			if (curr == Head)
			{
				newElement->Next = curr;
				curr = newElement;
				Head = curr;		
				return;
			}
			else
			{
				newElement->Next = curr;
				prev->Next=newElement;
				curr = newElement;
				return;
			}
		}
		else
		{
			prev = curr;
			count++;
		}

	}

}
void linkedListClass::retrieveList(linkedListStruct* list)
{ 
	while (list != NULL)
	{
		cout << list->data << endl;
		list = list->Next;
	}

}
void linkedListClass::retrieve()
{
	linkedListStruct *retrievePtr = new linkedListStruct;
	cout << "retrieving " << endl;
	linkedListStruct *split2 = new linkedListStruct;

	for (retrievePtr = Head; retrievePtr != NULL; retrievePtr = retrievePtr->Next)
	{
		cout << retrievePtr->data << endl;
	}
}
//O(N).Even if there are 100 elements, middle element is at 50 location. Constants dont matter in Big O.So we have O(N) = O(N/2).
void linkedListClass::middleLinkedList(linkedListStruct* list)
{
	linkedListStruct *fast = list;
	linkedListStruct *slow = list;

	if (list != NULL)
	{
		while (fast->Next != NULL && fast->Next->Next!=NULL)
		{
			slow = fast->Next;
			fast = fast->Next->Next;
		}
		cout << "Middle element is : " << slow->data<<endl;

	}

}
void linkedListClass::reverse(linkedListStruct* list)
{
	linkedListStruct *curr,*prev,*next;
	prev = NULL;
	curr = list;
	while (curr != NULL)
	{
		next = curr->Next;
		curr->Next = prev;
		prev = curr;
		curr = next;			
	}
	Head = prev;
	retrieve();
}
void linkedListClass::insertSort()
{
	linkedListStruct *current = new linkedListStruct;
	linkedListStruct *next = new linkedListStruct;
	linkedListStruct *tail = new linkedListStruct;

	tail = NULL;
	current = Head;
	while (current != NULL && tail != Head)
	{
		next = current;
		for (; next->Next != tail; next = next->Next)
		{
			if (next->data <= next->Next->data)
			{
				int temp = next->data;
				next->data = next->Next->data;
				next->Next->data = temp;
			}
		}
		tail = next;
		current = Head;
	}
	//	cout<<Head->data;
}
//mergesort time complexity worst case is O(nlogn).Space complexity is O(n)ie space is proportional to no. of elements.
linkedListStruct* linkedListClass::mergeSort(linkedListStruct* start, int size)
{
	int mid;
	linkedListStruct* first = new linkedListStruct;
	linkedListStruct* second = new linkedListStruct;

	if (size>1)
	{
		mid = size / 2;
		int count = mid;
		linkedListStruct *middle = new linkedListStruct;
		middle = start;
		while (count)
		{
			middle = middle->Next;
			count--;
		}
		first = mergeSort(start, mid);
		second = mergeSort(middle, size - mid);
		return merge(first, second, mid, size - mid);

	}
	else
		return start;
}
linkedListStruct* linkedListClass::merge(linkedListStruct *first, linkedListStruct *second, int size1, int size2)
{
	linkedListStruct *result = new linkedListStruct;
	result = NULL;
	if (size1 == 0)
		return second;
	if (size2 == 0)
		return first;
	if (first->data < second->data || first->data == second->data)
	{
		result = first;
		first->Next = merge(first->Next, second, size1 - 1, size2);
		return first;
	}
	else
	{
		result = second;
		second->Next = merge(first, second->Next, size1, size2 - 1);
		return second;
	}

	/*if (first == NULL)
	return(second);
	else if (second==NULL)
	return(first);

	if (first->data <= second->data)
	{
	result = first;
	result->Next = merge(first->Next, second);
	}
	else
	{
	result = second;
	result->Next = merge(first, second->Next);
	}
	return(result);*/

}
void linkedListClass::sortList()
{
	linkedListStruct *curr = new linkedListStruct;
	linkedListStruct *next = new linkedListStruct;
	linkedListStruct *temp = new linkedListStruct;
	linkedListStruct *prev = new linkedListStruct;
	linkedListStruct *prev2 = new linkedListStruct;

	bool flag;
	while (1)
	{
		flag = false;
		for (curr = Head; curr->Next != NULL; curr = curr->Next)
		{
			//temp = curr;

			if (curr->data > curr->Next->data)
			{
				if (curr == Head)
				{
					curr = curr->Next;
					temp->Next = curr->Next;
					curr->Next = temp;
					Head = curr;

				/*	temp = curr->Next;//can also be done this way
					curr->Next = temp->Next;
					temp->Next = curr;
					curr = temp;
					Head = curr;*/
				}
				else
				{
					temp = curr->Next;
					curr->Next = temp->Next;
					prev->Next = temp;
					temp->Next = curr;
					curr = temp;

				}
				flag = true;
			}
			prev = curr;

		}
		if (flag == false)//if flag ==false
			break;
	}
}


void linkedListClass::sortedListInsert(int newData)
{
	linkedListStruct *curr = new linkedListStruct;
	linkedListStruct *newPtr = new linkedListStruct;
	newPtr->data = newData;

	linkedListClass::sortList();
	for (curr = Head; curr != NULL; curr = curr->Next)
	{
		if (newData >= curr->data && curr->Next != NULL)//to check if newData is greater or equal and that curr is not the last element
		{
			if (newData < curr->Next->data)//to check that newData is smaller than the curr->Next. This acts as an in between clause
			{
				newPtr->Next = curr->Next;
				curr->Next = newPtr;
				break;
			}
		}
		else// to insert an element at last
		{
			newPtr->Next = curr->Next;
			curr->Next = newPtr;
			break;

		}

	}

}
void linkedListClass::countData()
{
	linkedListStruct *cntPtr = new linkedListStruct;
	int count = 0;
	for (cntPtr = Head; cntPtr != NULL; cntPtr = cntPtr->Next)
	{
		count++;
	}
	cout << "Count of all the elements in linked list is " << count << endl;
}
int linkedListClass::count(linkedListStruct* list)
{
	linkedListStruct *cntPtr = new linkedListStruct;
	int count = 0;
	for (cntPtr = list; cntPtr != NULL; cntPtr = cntPtr->Next)
	{
		count++;
	}
	return count;
}
void linkedListClass::showDuplicate()
{//O(n^2)
	linkedListStruct *iPtr = new linkedListStruct;
	linkedListStruct *jPtr = new linkedListStruct;

	int n = 0;

	for (iPtr = Head; iPtr != NULL; iPtr = iPtr->Next)
	{
		for (jPtr = iPtr->Next; jPtr != NULL; jPtr = jPtr->Next)
		{
			if (iPtr->data == jPtr->data)
			{
				cout << iPtr->data << endl;
				n++;
			}
			
		}
	}
	// cout<<"Total number of duplicate elements are : "<<n<<endl;
}

void linkedListClass::removeDuplicate()
{	linkedListStruct *iPtr = new linkedListStruct;
	linkedListStruct *jPtr = new linkedListStruct;
	linkedListStruct *kPtr = new linkedListStruct;
	linkedListStruct *oldPtr = new linkedListStruct;
	for (iPtr = Head; iPtr != NULL; iPtr = iPtr->Next)
	{
		kPtr = iPtr;
		for (jPtr = iPtr->Next; jPtr != NULL; kPtr = kPtr->Next)
		{
			if (iPtr->data == jPtr->data)
			{
				oldPtr = jPtr;
				kPtr->Next = oldPtr->Next;//jPtr->Next; could also be used
				jPtr = jPtr->Next;
				delete oldPtr;

			}
			else
			{
				jPtr = jPtr->Next;
			}
		}
	}
/*	removing duplicates from sorted list Time complexity is O(n)
//if the list is unsorted,use merge sort to sort the list O(nlogn) and then remove duplicates.Quicksort can also be used but for worst case it is O(n^2)

iPtr = Head;

   while (iPtr->Next != NULL)
	{
		if (iPtr->data == iPtr->Next->data)
		{
			oldPtr = iPtr->Next;
			iPtr->Next = iPtr->Next->Next;
			delete(oldPtr);
		}
		else
		{
			iPtr = iPtr->Next;
		}
	}
	*/
}
void linkedListClass::deleteLinkedList(linkedListStruct *list)
{
	linkedListStruct *curr = new linkedListStruct;
	while (list != NULL)
	{
		curr = list;
		list = list->Next;
		Head = list;
		delete curr;

	}
	Head = NULL;
}
void linkedListClass::shuffleMerge()
{
	linkedListStruct *list1 = new linkedListStruct;	//new operator used over malloc to create a memory block
	linkedListStruct *list2 = new linkedListStruct;
	linkedListStruct *temp1 = new linkedListStruct;
	linkedListStruct *temp2 = new linkedListStruct;

	linkedListStruct *retrievenodeptr = new linkedListStruct;
	list1 = Head;
	list2 = Head2;

	while ((list1 || list2) != NULL)
	{ //bellow is also one way to do it,which is commented out	 			
		/*	temp1=list1;
		temp2=list2;
		list1 = list1->Next;
		list2 = list2->Next;

		if(temp1->Next == NULL)
		{
		temp1->Next = temp2;
		break;
		}
		else if(temp2->Next==NULL)
		{
		temp1->Next = temp2;
		temp2->Next = list1;
		break;
		}
		else
		{
		temp1->Next = temp2;
		temp2->Next = list1;
		}
		*/
		
		temp1 = list1->Next;
		list1->Next = list2;

		list2 = list2->Next;
		list1 = list1->Next;
		list1->Next = temp1;
		list1 = list1->Next;
		if (list1->Next == NULL)
		{
			list1->Next = list2;
			//list2 = list2->Next;
			break;
		}




	}

	for (retrievenodeptr = Head; retrievenodeptr != NULL; retrievenodeptr = retrievenodeptr->Next)
	{
		cout << retrievenodeptr->data << endl;
	}

}
void linkedListClass::alternateSplit()
{
	linkedListStruct *splitHead1 = new linkedListStruct;
	linkedListStruct *splitHead2 = new linkedListStruct;
	linkedListStruct *split1 = new linkedListStruct;
	linkedListStruct *split2 = new linkedListStruct;

	linkedListStruct *ret1 = new linkedListStruct;
	linkedListStruct *ret2 = new linkedListStruct;

	splitHead1 = Head;
	splitHead2 = Head->Next;

	split1 = splitHead1;
	split2 = splitHead2;

	while (split1 != NULL && split1->Next->Next != NULL)
	{
		split1->Next = split1->Next->Next;
		split1 = split1->Next;

		split2->Next = split2->Next->Next;
		split2 = split2->Next;
	/*	split1->Next = split2->Next;
		split1 = split1->Next;
		split2->Next = split1->Next;
		split2 = split2->Next;*/

	}
	split1->Next = NULL;
	for (ret1 = splitHead1; ret1 != NULL; ret1 = ret1->Next)
	{
		cout << ret1->data << endl;
	}
	for (ret2 = splitHead2; ret2 != NULL; ret2 = ret2->Next)
	{
		cout << "sec" << ret2->data << endl;
	}

}
void linkedListClass::palindrome(linkedListStruct *list)
{
	//the middle of the linked list
	linkedListStruct *fast = list;
	linkedListStruct *slow = list;
	linkedListStruct *prevSlow = NULL;
	linkedListStruct *secondHalfList = NULL;
	linkedListStruct *midNode = NULL;
	linkedListStruct *afterMiddle = NULL;


	if (list != NULL)
	{
		while (fast->Next != NULL && fast->Next->Next != NULL)//logic to find the middle of the linked list
		{

			fast = fast->Next->Next;
			slow = slow->Next;
			midNode = slow;//this is the middle element of the list
		}
		afterMiddle = slow->Next;//track the next element of the list
		midNode->Next = NULL;

		linkedListStruct * reverseList = reversePalindromeList(afterMiddle);//reverse the second half of list
		int compareResult = linkedListClass::compareList(list, reverseList);
		linkedListStruct * secondHalfList = reversePalindromeList(reverseList);//the reverse list is made to original list as second half

		midNode->Next = secondHalfList;//combine the first list to the second list that was separated,reversed and then again reversed back to original.
		if (compareResult)
			cout << "List is palindrome" << endl;
		else
			cout << "Not a palindrome" << endl;

	}

	/*//below also works
	if (list != NULL)
	{
		while (fast != NULL && fast->Next != NULL)//logic to find the middle of the linked list
		{
			fast = fast->Next->Next;
			prevSlow = slow;
			slow = slow->Next;
		}
		if (fast != NULL)//fast pointer will be null if there are even elements.This logic can also be used to find if there are even or odd elements
		{
			midNode = slow;
			slow = slow->Next;
		}
		//middle is found, separate the LHS and RHS
		prevSlow->Next = NULL;
		secondHalf = slow;
		linkedListStruct * reverseList = reversePalindromeList(secondHalf);//reverse the second half of list
		int compareResult = linkedListClass::compareList(list, reverseList);
		linkedListStruct * secondHalfList = reversePalindromeList(reverseList);//the reverse list is made to original list as second half

		if (midNode != NULL)
		{
			prevSlow->Next = midNode;
			midNode->Next = secondHalfList;
		}
		else
		{
			prevSlow->Next = secondHalfList;
		}
		if (compareResult)
			cout << "List is palindrome" << endl;
		else
			cout << "Not a palindrome" << endl;
	}
*/
}
int linkedListClass::compareList(linkedListStruct *firstList, linkedListStruct *reverseList)
{
	int flag = 0;
	while (firstList != NULL && reverseList != NULL)
	{
		if (firstList->data == reverseList->data)
			flag = 1;
		else
			flag=0;

		firstList = firstList->Next;
		reverseList = reverseList->Next;
	}
	if (flag)
		return 1;
	else
		return 0;
	/*if (firstList == NULL && reverseList == NULL)
		return 1;
	else 
		return 0;*/
}
linkedListStruct * linkedListClass::reversePalindromeList(linkedListStruct *list)
{
	linkedListStruct *prev = NULL;
	linkedListStruct *current = list;
	linkedListStruct *next;
	while (current != NULL)
	{
		next = current->Next;
		current->Next = prev;
		prev = current;
		current = next;
	}
	list = prev;
	
	return list;
}

int main()
{
	int option;
	int insertElement, secondData;
	int data, position;
	linkedListClass *classPtr = new linkedListClass();
	linkedListStruct* newhead = new linkedListStruct();
	linkedListStruct* temp = new linkedListStruct();


	do
	{
		cout << "1. Insert element" << endl;
		cout << "2. Count elements" << endl;
		cout << "3. Show duplicates" << endl;
		cout << "4. Remove duplicates" << endl;
		cout << "5. Retrieve all elements" << endl;
		cout << "6. Insert an element in linked list" << endl;
		cout << "7. Sort the linked list" << endl;
		cout << "8. Insert in a sort list" << endl;
		cout << "9. InsertSort" << endl;
		cout << "10. Insert in Second List" << endl;
		cout << "11. Append List" << endl;
		cout << "12. Intersection List" << endl;
		cout << "13. Intersection List better complexity" << endl;
		cout << "14. Alternate Split" << endl;
		cout << "15. Shuffle Merge" << endl;
		cout << "16. Reverse" << endl;
		cout << "17. Merge Sort" << endl;
		cout << "18. Delete linked list" << endl;
		cout << "19. Middle of linked list" << endl;
		cout << "20. Check if list is Palindrome" << endl;
		cout << "21. Delete element in linked list" << endl;

		cout << "22. Exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1:  cout << "Enter the elements in linked list" << endl;
			cin >> data;
			classPtr->insert(data);
			break;
		case 2:  cout << "Count the elements in linked list" << endl;
			classPtr->countData();
			break;
		case 3:  cout << "Show duplicate the elements in linked list" << endl;
			classPtr->showDuplicate();
			break;
		case 4:  cout << "Remove duplicate the elements in linked list" << endl;
			classPtr->removeDuplicate();
			break;
		case 5:  cout << "Retrieve the elements in linked list" << endl;
			classPtr->retrieve();
			break;
		case 6:  cout << "Insert element in linked list" << endl;
			cin >> data;
			cout << "Which position ?" << endl;
			cin >> position;
			classPtr->insertElement(data, position);
			break;
		case 7:  cout << "Sort the linked list" << endl;
			classPtr->sortList();
			break;
		case 8:  cout << "Insert in a sorted linked list" << endl;
			cout << "Insert an element" << endl;
			cin >> insertElement;
			classPtr->sortedListInsert(insertElement);
			break;
		case 9:  cout << "InsertSort" << endl;
			classPtr->insertSort();
			break;
		case 10:  cout << "Insert in second list" << endl;
			cin >> secondData;
			classPtr->insertSecond(secondData);
			break;
		case 11:  cout << "Append linked list" << endl;
			classPtr->appendList();
			break;
		case 12:  cout << "Intersection linked list" << endl;
			classPtr->intersectionList();
			break;
		case 13:  cout << "Intersection linked list better complexity" << endl;
			classPtr->intersectionListComp();
			break;
		case 14:  cout << "Alternating split" << endl;
			classPtr->alternateSplit();
			break;
		case 15:  cout << "Shuffle Merge" << endl;
			classPtr->shuffleMerge();
			break;
		case 16:
			classPtr->reverse(classPtr->Head);
			break;
		case 17:  cout << "Merge Sort" << endl;
			int listSize, count;
			listSize = classPtr->count(classPtr->Head);
			newhead = classPtr->mergeSort(classPtr->Head, listSize);
			temp = newhead;
			 count = 0;
			while (count != listSize - 1)
			{
				temp = temp->Next;
				count++;
			}
			temp->Next = NULL;
			classPtr->retrieveList(newhead);
			break;
		case 18:
			classPtr->deleteLinkedList(classPtr->Head);
			break;	
		case 19:
			classPtr->middleLinkedList(classPtr->Head);
			break;
		case 20:
			classPtr->palindrome(classPtr->Head);
			break;
		case 21:
			int delElement;
			cout << "Enter data to delete" << endl;
			cin >> delElement;
			classPtr->deleteElement(delElement);
			break;

			//	default: break;

		}

	} while (option != 22);
	return 0;
}