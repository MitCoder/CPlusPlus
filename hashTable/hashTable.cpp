/*
Hash Table
1. Insert 
2. Count items associated with an index in hash table
3. print elements
4. remove element from hash table
Analysis: Expected length of chain(ie linked list) for n keys and m slots(ie size) will be n/m. O(1+n/m),
where 1 is for doing hash fn calculation and n/m(load factor aka alpha)
*/

#include<iostream>
#include "hashTable.h"
using namespace std;

hashClass :: hashClass(){

 	tableSize=5;	

};

int hashClass::hashFn(std::string key)
{
	int hash=0;
	int index;
	
	for(int i=0;i<key.length();i++)
	{   
		hash=hash+(int)key[i];
	}
	
	index=hash % hashClass::tableSize;
	return index;
}

void hashClass::insert(std::string key,node *hashNode)
{
	int index=hashClass::hashFn(key);//Creates an index for the key
	
	if(hashNode[index].name=="empty")
	{ 
		hashNode[index].name=key;
		hashNode[index].next=NULL;
	}
	else
	{		
		node *tempPtr=new node;
		tempPtr=&hashNode[index];
		node *newNode= new node;
		newNode->name=key;
		newNode->next=NULL;
			
		while(tempPtr->next!=NULL)
		{
			tempPtr=tempPtr->next;
		
		}
		tempPtr->next=newNode;		

	}//else end
}
int hashClass::countItemsList(int keyIndex,node *hashNode)
{ 
	int count=0;
	
	if(hashNode[keyIndex].name=="empty")
	{
		return count;
	}
	else
	{	
		node *tempPtr=hashNode;
		tempPtr=&hashNode[keyIndex];
		if(tempPtr->next!=NULL)
		{			
			while(tempPtr->next!=NULL)
			{	count++;
				tempPtr=tempPtr->next;
			}			
		}
		
	}
	return count;

}

void hashClass::hashTablePrint(node *hashNode)
{

	for(int i=0;i<hashClass::tableSize;i++)
	{			
		int count= countItemsList(i,hashNode);//count the recurring items in the list
	
		cout<<"Item Name:"<<hashNode[i].name<<" at index "<<i<<endl;
		cout<<"Count of item:"<<count<<endl;
		cout<<"---------------------------------"<<endl;
	}
	
}
void hashClass::removeItem(std::string delItem,node *hashNode)
{
	int index=hashFn(delItem);
	node *delPtr;
	
	if(hashNode[index].name == "empty" && hashNode[index].next==NULL)
	{
		cout<<delItem<<" Not found"<<endl;
	}
	else if(hashNode[index].name == delItem && hashNode[index].next==NULL)//only one item present in the table
	{   
		hashNode[index].name="empty";
	}
	else if (hashNode[index].name == delItem && hashNode[index].next!=NULL)//present in hash table and there is a list for that item
	{
		//	delPtr=&hashNode[index];
		hashNode[index]=*(hashNode[index].next);
		cout<<hashNode[index].name<<endl;
		cin.get();		
	}
	else
	{
		node *ptr1;
		node *ptr2;
		ptr1=hashNode[index].next;
		ptr2=&hashNode[index];

		while(ptr1!=NULL && ptr1->name!=delItem)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;		
		}//ptr2 points to prev and ptr1 the next one
		
		if(ptr1==NULL)
		{
			cout<<"Item in list not available"<<endl;
		}
		else
		{	ptr2->next=ptr1->next;
			delete ptr1;	
		}
	}
}
int main()
{
	
	hashClass *classPtr = new hashClass();
	std::string key;
	std::string keyFind;
	std::string removeItem;
	int count, keyIndex;
	node *hashNode=new node [classPtr->tableSize];
	
	for(int i=0;i<classPtr->tableSize;i++)
	{	
			hashNode[i].name="empty";
			hashNode[i].next=NULL;
	}
	
	while(1)
	{
		cout<<"Enter options"<<endl;
		cout<<"1. Enter data"<<endl;
		cout<<"2. Find recurring items"<<endl;
		cout<<"3. Print list"<<endl;
		cout<<"4. Remove items"<<endl;
		cout<<"5. Exit"<<endl;

		int option;
		cin>>option;
		
		switch(option)
		{
			case 1:	cout<<"Enter data"<<endl;
					for(int i=0;i<classPtr->tableSize;i++)
					{	cin>>key;
						classPtr->insert(key,hashNode);
					}
					break;
			case 2: cout<<"Enter the item to find the items in the list"<<endl;
					cin>>keyFind;
					keyIndex=classPtr->hashFn(keyFind);

					count=classPtr->countItemsList(keyIndex,hashNode);
					cout<<endl;
					cout<<"Index name : "<<hashNode[keyIndex].name<<" has "<<count<<" elements"<<endl;		

					if(count >0)
					{
						cout<<"Below are items associated with :"<<hashNode[keyIndex].name<<endl;
						node *tempPtr=hashNode;
						tempPtr=&hashNode[keyIndex];
						if(tempPtr->next!=NULL)
						{			
							while(tempPtr!=NULL)
							{	cout<<tempPtr->name<<endl;
								tempPtr=tempPtr->next;
							}			
						}
					}
					break;
			case 3:	
					classPtr->hashTablePrint(hashNode);
					break;
			case 4:	cout<<"Enter the item to remove"<<endl;
					cin>>removeItem;
					classPtr->removeItem(removeItem,hashNode);
					cout<<"--------------"<<endl;
					break;
			case 5:  exit(1);
		}
	
	}

	return 0;
}