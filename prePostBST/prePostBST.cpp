#include<iostream>
using namespace std;

struct Node
{
	char data;
	Node *left;
	Node *right;
};

Node* buildTree(char inOrder[], char preOrder[], int start, int end);
int search(char inOrder[], int start,int end, char findChar);
Node *newNode(char data);
void printInOrder(Node *bst);



int main()
{
	char inOrder[] = {'D','B','E','A','F','C','\0'};
	char preOrder[] = {'A','B','D','E','C','F','\0'};
	int len = sizeof(inOrder) / sizeof(inOrder[0]);
	Node *root= buildTree(inOrder, preOrder, 0, len-2);
	cout << "printing" << endl;

	printInOrder(root);
	getchar();

}
Node* buildTree(char inOrder[], char preOrder[], int start, int end)
{
	static int preIndex = 0;
	if (start > end)
		return NULL;

	struct Node *bst = new Node;	

	bst = newNode(preOrder[preIndex++]);

	if (start == end)
		return bst;
	//cout << bst->data << endl;
	//cin.get();
	int index = search(inOrder, start,end, bst->data);
	bst->left = buildTree(inOrder, preOrder, start, index-1);
	bst->right = buildTree(inOrder, preOrder, index+1, end);

	return bst;
	
}
int search(char inOrder[],int start,int end, char findChar)
{
	for (int i = start; i <=end; i++)
	{
		if (inOrder[i] == findChar)
		{
			return i;
		}
	}

}
Node *newNode(char data)
{
	struct Node *newnode = new Node;
	newnode->data = data;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}
void printInOrder(struct Node *bst)
{
	if (bst == NULL)
		return ;
	printInOrder(bst->left);
		cout << bst->data << endl;
		cin.get();
	printInOrder(bst->right);

}
