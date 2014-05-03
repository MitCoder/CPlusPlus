#include<iostream>
using namespace std;

struct node
{
	char* name;
	node *next;
};
struct word
{
	char *str;
};
struct copyArr
{
	struct word *array;
	int size;
};

class anagramHastTable{
public:
	anagramHastTable();
	int hashFn(char* key,int tableSize);
	static int compChar(const void* a, const void* b);
	void insert(char* key[],int size, node *hashNode);
};