//binarytree.cpp
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
class binaryTree
{
	public:
		binaryTree();
		node* add(int data);
		bool btSame(node *root1, node *root2);
		node *root;
		int isBST(node *root);

};
binaryTree::binaryTree()
{
	root = NULL;
}
//check if given binary tree is BST or not
int binaryTree::isBST(node *tree)
{
	//return 1==true and 0==false
	if (tree == NULL)
		return 1;// an empty tree is bst

	if (tree->left != NULL && tree->left->data > tree->data)
		return 0;
	if (tree->right != NULL && tree->right->data <= tree->data)
		return 0;
	
	int leftVal = isBST(tree->left);
	int rightVal = isBST(tree->right);
	
	/* below if and else condition also works
	if (!isBST(tree->left) || !isBST(tree->right))
		return 0;//return false

	else
		return 1;//return true
		*/
	if (leftVal && rightVal)
		return 1;
	else
		return 0;
}
//check if two binary trees are same
bool  binaryTree::btSame(node *tree1, node *tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;

	if (tree1->data == tree2->data)
	{
		bool leftVal = btSame(tree1->left, tree2->left);
		bool rightVal = btSame(tree1->right, tree2->right);

		if (leftVal && rightVal)
			return true;
		else
			return false;
	}
	else
		return false;

}
node* binaryTree::add(int data)
{
		node *newNode = new node;
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
}
int main()
{
	int option;
	bool flag;
	binaryTree *binaryTreePtr = new binaryTree();
	binaryTreePtr->root = binaryTreePtr->add(6);
	binaryTreePtr->root->left = binaryTreePtr->add(5);
	binaryTreePtr->root->right = binaryTreePtr->add(7);
	binaryTreePtr->root->left->left=binaryTreePtr->add(3);
	binaryTreePtr->root->left->left->right = binaryTreePtr->add(4);


	binaryTree *binaryTreePtr2 = new binaryTree();
	binaryTreePtr2->root = binaryTreePtr2->add(6);
	binaryTreePtr2->root->left = binaryTreePtr2->add(5);
	binaryTreePtr2->root->right = binaryTreePtr2->add(7);
	binaryTreePtr2->root->left->left = binaryTreePtr2->add(3);
	binaryTreePtr2->root->left->left->right = binaryTreePtr2->add(4);
		
	do
	{
		cout << "Enter options" << endl;
		cout << "1. is BST or not" << endl;
		cout << "2. check if two trees are same" << endl;

		cout << "4. quit" << endl;
		cin >> option;
		switch (option)
		{
			/*case 1:
			int data;
			cin >> data;
			binaryTreePtr->add(binaryTreePtr->root, data);
			break;*/

		case 1: int returnVal;
			returnVal=binaryTreePtr->isBST(binaryTreePtr->root);
			if (returnVal)
			cout << "value return " << returnVal<<"BST" << endl;
			else
			cout << "value return " << returnVal << "not BST" << endl;

			break;
		case 2:			
			flag=binaryTreePtr->btSame(binaryTreePtr->root, binaryTreePtr2->root);
			if (flag)
				cout << "trees are same" << endl;
			else
				cout << "not same" << endl;
			break;
		case 4: exit(1);
			break;

		}

	} while (option!=4);
	
	return 0;

}