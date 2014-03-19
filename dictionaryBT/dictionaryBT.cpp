#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
	char word[127], meaning[256];
	node *left;
	node *right;
};
class dictionaryBST
{
    public:
	node *root;
	void insert(node *root, char *word, char *meaning);
	void find(node *root, char *word);
	dictionaryBST()
	{
		root = NULL;
	}

};
void dictionaryBST::insert(node *temp,char *word,char *meaning)
{
	node *newNode = new node;
	strcpy_s(newNode->word, word);
	strcpy_s(newNode->meaning, meaning);
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL)
	{
		root = newNode;
		cout << "root null" << root->word << endl;
		return;
	}

	if (0>_stricmp(temp->word, newNode->word))//temp is greater than newnode
	{
		if (temp->right == NULL)
		{
			temp->right = newNode;
			temp = temp->right;
			strcpy_s(temp->word, newNode->word);
			strcpy_s(temp->meaning, newNode->meaning);
			cout << " right " << temp->word << endl;

		}
		else
			insert(temp->right, newNode->word, newNode->meaning);
	}
	else
	{
		if (temp->left == NULL)
		{
			temp->left = newNode;
			temp = temp->left;
			strcpy_s(temp->word, newNode->word);
			strcpy_s(temp->meaning, newNode->meaning);
			cout <<"left"<< temp->word << endl;
		}
		else
			insert(temp->left, newNode->word, newNode->meaning);

	}
	return;
}
void dictionaryBST::find(node *temp, char *word)
{
	if (root == NULL)
		return;

	while (temp)
	{
		if (0 == _stricmp(temp->word, word))//temp is equal than newnode
		{
			cout << "Word looking for :" << temp->word << endl;
            cout<<"Word found:" << word << endl;
			break;
			return;
		}
		if (0 > _stricmp(temp->word, word))//temp is greater than newnode
		{
          temp=temp->right;
		 /// cout << temp->word << word << _stricmp(temp->word, word) << "temp is greater" << endl;
		}
		else
		{
			temp = temp->left;
		//	cout << temp->word << word << _stricmp(temp->word, word) << "temp is less"<<endl;

		}
	}
	return;

}
int main()
{
	int option;
	dictionaryBST bstPtr;
	node *addNode;
	char word[128];
	char meaning[256];
	while (1)
	{
		cout << "Choose options" << endl;
		cout << "1. Enter the element in tree" << endl;
		cout << "2. Find meaning of word in tree" << endl;

		cout << "3. Quit" << endl;

		cin >> option;
		switch (option)
		{

		case 1:
			cout << "Insert word in tree" << endl;
			cin >> word;
			cout << "Insert meaning in tree" << endl;
		    cin >> meaning;
			bstPtr.insert(bstPtr.root, word,meaning);

			break;
		case 2:
			cout << "Enter word to be found in tree" << endl;
			cin >> word;			
			bstPtr.find(bstPtr.root, word);
			break;

		case 3:     exit(1);

		}
	}
}
