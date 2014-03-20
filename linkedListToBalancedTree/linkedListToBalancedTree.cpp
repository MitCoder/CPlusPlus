#include<iostream>
using namespace std;

struct listNode
{
	int data;
	listNode *next;
};
struct treeNode
{
	int data;
	treeNode *left;
	treeNode *right;
};
class balancedTree
{
public:
	listNode *head;
	balancedTree()
	{
	//	root = NULL;
		head = NULL;
	}
	void insert(int data);
	treeNode * treeInsert(int data);

	void printList(listNode *head);
	int countListItems(listNode *head);
	void convertBalancedTree(listNode *head);
	treeNode * convertBalancedTreeUtil(listNode **head, int count);
	void preOrderTraversal(treeNode *tree);

};
void balancedTree:: insert(int data)
{
	listNode *newNode = new listNode;
	newNode->data = data;
	newNode->next = head;
	head = newNode;	
}
treeNode * balancedTree::treeInsert(int data)
{
	treeNode *newNode = new treeNode;
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}
void balancedTree:: printList(listNode *head)
{   
	cout << "Printing list" << endl;
	listNode *temp = new listNode;
	for (temp = head; temp != NULL; temp = temp->next)
		cout << temp->data<<" " ;
}
void balancedTree::preOrderTraversal(treeNode *tree)
{
	if (tree == NULL)
		return;
	cout<<tree->data<<" ";
	preOrderTraversal(tree->left);
	preOrderTraversal(tree->right);

}
void balancedTree::convertBalancedTree(listNode *head)
{
	int count=balancedTree::countListItems(head);
	treeNode *test = convertBalancedTreeUtil(&head, count);
	cout << "\npreOrder traversal is :"<<endl;
	preOrderTraversal(test);
}
//create a balanced tree from bottom up approach. ie from leaves to root
treeNode * balancedTree::convertBalancedTreeUtil(listNode **head, int count)
{
	if (count <= 0)
		return NULL;

	treeNode *left = convertBalancedTreeUtil(head, count / 2);

	treeNode *root=balancedTree::treeInsert((*head)->data);
	root->left = left;

	*head = (*head)->next;
	root->right = convertBalancedTreeUtil(head, count - count / 2 - 1);
	return root;
}
int balancedTree::countListItems(listNode *head)
{
	listNode *temp = new listNode;
	int count=0;
	for (temp = head; temp != NULL; temp = temp->next)
		count++;
	return count;
}
int main()
{
	balancedTree *classPtr = new balancedTree();
	classPtr->insert(7);
	classPtr->insert(6);
	classPtr->insert(5);
	classPtr->insert(4);
	classPtr->insert(3);
	classPtr->insert(2);
	classPtr->insert(1);


	classPtr->printList(classPtr->head);
	classPtr->convertBalancedTree(classPtr->head);
	
	cin.get();

}