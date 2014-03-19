// suffix tree used to find the longest prefix of a string in a given array
#include<iostream>
using namespace std;
#define ALPHABET_SIZE 26 

struct trieNode
{
	int value;
	trieNode *children[ALPHABET_SIZE];
};
struct trie
{
	trieNode *root;
	int count;
};


void init(struct trie *trieStruct);
trieNode * getNode();
void insert(struct trie *trieStruct, char *str);
int search(struct trie *trieStruct, char *searchStr);

void init(struct trie *trieStruct)
{
	trieStruct->root = getNode();
	trieStruct->count = 0;
}
//initialize the parent node to have 26 children nodes.
trieNode * getNode()
{
	trieNode *node = new trieNode;
	node->value = 0;
	if (node)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			node->children[i] = NULL;
		}
	}
	return node;
}
void insert(struct trie *trieStruct, char *str)
{
	trieNode *node = trieStruct->root;
	trieStruct->count++;
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		int index = int(str[i]) - (int)'a'; //ascii value of 'a' is 97.
		if (node->children[index] == NULL)
		{
			node->children[index] = getNode();
		}
		node = node->children[index];

	}
	//leaf node will have the count value
	node->value = trieStruct->count;

}
int search(struct trie *trieStruct, char *searchStr)
{
	trieNode *node = new trieNode;
	node = trieStruct->root;
	int prefixCount = 0;
	for (int i = 0; i < strlen(searchStr); i++)
	{
		int index = int(searchStr[i]) - (int)'a';
		if (node->children[index] == NULL)
		{
			return prefixCount;
		}
		node = node->children[index];
		prefixCount = node->value;
	}

	return -1;

}
int main()
{

	char keys[][9] = { "are", "basement", "part", "cat", "cater", "the", "their", "cantel" };
	trie *trieStruct = new trie;

	init(trieStruct);
	//insert keysArr in trie
	for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
	{
		insert(trieStruct, keys[i]);
	}

	//search array
	char searchArr[][8] = { "cats", "them" };
	for (int i = 0; i < sizeof(searchArr) / sizeof(searchArr[0]); i++)
	{
		int count = search(trieStruct, searchArr[i]);
		if (count >= 0)
			cout << "Longest prefix of search string ->" << searchArr[i] << " is " << keys[count - 1] << " and position in trie is " << count << endl;
	}
	cin.get();

	return 0;
}