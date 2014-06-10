#include<iostream>
#include<string>
using namespace std;

struct node
{
	string name;	
	node *next;
};
 

class hashClass
{
	public:
	hashClass();
	int hashFn(std::string key);
	void insert(std::string key,node *hashNode);
	int countItemsList(int index,node *hashNode);
	void hashTablePrint(node *hashNode);
	void removeItem(std::string removeItem,node *hashNode);
	//static const int tableSize=5;
	int tableSize;
	
};