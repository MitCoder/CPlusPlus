#include<iostream>
using namespace std;
#define ALPHABET_SIZE 26

struct trieNode
{
	int value;
	trieNode *children[ALPHABET_SIZE];

};
//trie structure which contains root of of type trienNode and a counter of all nodes
struct trie
{
	trieNode *root;
	int count;
};

void init(trie *trie);
trieNode *getNode();
void insert(trie *trie,char *arr);
void search(trie *trie, char *arr);

void init(trie *trie)
{
	trie->root = getNode();
	trie->count = 0;
}
trieNode *getNode()
{
	
	/*trieNode *node = NULL;
	node = (trieNode *)malloc(sizeof(trieNode));
	*/
	trieNode *node = new trieNode();
	if (node)
	{	node->value = 0;
		
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			node->children[i] = NULL;
		
		}
	}
	return node;

}
void insert(trie *trieStruct,char *keys)
{
	trieNode *node  =trieStruct->root;
	int keyLength = strlen(keys);
	trieStruct->count++;
	for (int i = 0; i < keyLength; i++)
	{
		int index = (int)keys[i] - (int)('a');
		if (!node->children[index])	//	if(node->children[index] == NULL)
		{
			node->children[index] = getNode();
		//	cout << "inside null "<<" index "<<index<<" str "<<keys[i]<<" char "<<keys<<endl;
		//	cin.get();
		}
		node = node->children[index];
	}
	//eventually the leaf node, will have the value count
	node->value=trieStruct->count;

}
void search(trie *trieStruct, char *str)
{
	int len = strlen(str);
	trieNode * node=trieStruct->root;

	for (int i = 0; i < len; i++)
	{
		int index = int(str[i]) - (int)('a');
		if (node->children[index] == NULL)
		{
			cout << str<<" not found " << endl;
			cin.get();
			return;
		}

		node = node->children[index];
	}
	if (node->value >0)
	{
		cout <<str<< " string found " << endl;
		cin.get();
		return;
	}
}
int main()
{
	char keys[][8] = { "shopper", "a", "shop", "answer", "shopper", "by", "bypass", "pass" };
	trie *trieStruct=new trie;
	
	init(trieStruct);
	
	for (int i = 0; i < sizeof(keys) / sizeof(keys[0]);i++)
	insert(trieStruct,keys[i]);

	search(trieStruct, "pass");
	search(trieStruct, "bypass");
	search(trieStruct, "shop");
	search(trieStruct, "anss");
	search(trieStruct, "a");


}