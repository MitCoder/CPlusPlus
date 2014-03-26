/*Binary search tree
1. Insert elements in a tree
2. Find a specific element in tree
3. Display all elements of tree
4. Delete an element in tree
5. PreOrder Traveral
6. InOrder Traveral
7. PostOrder Traveral
8. LCA of BST
9. Display levelwise BST
10. Check level of leaf nodes
11. Max distance from root
12. Find distance of node from root
13. Print all possible paths
14. Convert BST to Doubly linked list
15. Convert BST to Doubly linked list using queue
16. Mirror a BST
17. Diameter of BST
18. Height of BST
19. Delete all  nodes of BST
20. Find a path whose sum is equal is a number
21. Find the successor of a given node
22. Find the next minmum node in a tree from the given node
23. Check if bst is height balanced
*/
#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};
struct nodeQueue
{
	int data;
	node *next;

};

class bst
{
public:
	node * root;
	void insert(node *, node *);
	void display(node *, int level);
	void displayLevel(node *, int level);//This is breadth first search 
	void printPossiblePaths(node *root, int arr[], int len);//prints all the paths in bst
	int maxdistRoot(node *, int level);
	int nodedistRoot(node *, int level, int find);
	int heightBST(node *);
	//void find(node *, int item);
	node* find(node *, int item);
	void deleteNode(int item);
	void bstToDLL(node *node);
	node *bstToDLLConvert(node *node);
	void bstToDLLQueue(node *node);
	void mirror(node *node);
	void findDelNode(int item, node **parent, node **location);
	void case_a(node *location, node *parent);
	void case_b(node *location, node *parent);
	void case_c(node *location, node *parent);
	node* LCA(node *rootNode, int val1, int val2);
	bool checkLeafLevel(node *rootNode, int currlevel, bool flag);
	//Depth first traversal for bst includes preOder,inOrder and postOrders
	void preOrder(node * root);//it works based on VLR
	void inOrder(node * root);//it works based on LVR
	void postOrder(node * root);//it works based on LRV
	int diameter(node * root);
	void hasPathSum(node * root,int val,int sumVal);
	void deleteAllBST(node * root);
	node *minNode(node *root);
	void bstSuccessor(node *root, int findSuccVal);
	int isBalanced(node *root, int *height);
	bst()
	{
		root = NULL;
	}
};

int main()
{
	int option, findElement, delElement;
	bst bstPtr;
	node *addNode;

	while (1)
	{
		cout << "Choose options" << endl;
		cout << "1. Enter the element in tree" << endl;
		cout << "2. Display" << endl;
		cout << "3. Find an element" << endl;
		cout << "4. Delete an element" << endl;
		cout << "5. PreOrder Traversal" << endl;
		cout << "6. InOrder Traversal" << endl;
		cout << "7. PostOrder Traversal" << endl;
		cout << "8. LCA" << endl;
		cout << "9. Display levelwise BST" << endl;
		cout << "10. Check level of leaf nodes" << endl;
		cout << "11. Max distance from root" << endl;
		cout << "12. Find distance of node from root" << endl;
		cout << "13. Print possible paths" << endl;
		cout << "14. Convert BST to DLL" << endl;
		cout << "15. Convert BST to DLL using queue" << endl;
		cout << "16. Mirror BST" << endl;
		cout << "17. Diameter BST" << endl;
		cout << "18. Height BST" << endl;
		cout << "19. Delete all nodes of BST" << endl;
		cout << "20. Find a path whose sum is equal is a number" << endl;
		cout << "21. Find successor in BST" << endl;
		cout << "22. Check if BST is height balanced" << endl;

		cout << "24. Quit" << endl;

		cin >> option;
		switch (option)
		{

		case 1:		
				addNode = new node();
				cout << "Insert element in tree" << endl;
				cin >> addNode->data;
				bstPtr.insert(bstPtr.root, addNode);
				break;
		case 2:		
				bstPtr.display(bstPtr.root, 1);
				break;
		case 3:
				{
				cout << "Enter which element to find" << endl;
				cin >> findElement;
				node * findElementNode = bstPtr.find(bstPtr.root, findElement);
				cout << "Item found " << findElementNode->data << endl;
				break;
				}
		case 4:		
				cout << "Enter which element to delete" << endl;
				cin >> delElement;
				bstPtr.deleteNode(delElement);
				break;
		case 5:		
				cout << "PreOrderTraversal" << endl;
				bstPtr.preOrder(bstPtr.root);
				break;
		case 6:		
				cout << "InOrderTraversal" << endl;
				bstPtr.inOrder(bstPtr.root);
				break;
		case 7:		
				cout << "PostOrderTraversal" << endl;
				bstPtr.postOrder(bstPtr.root);
				break;
		case 8:	
				cout << "Enter val1 " << endl;
				node *ptrLCA;
				int val1, val2;
				cin >> val1;
				cout << "Enter val2 " << endl;
				cin >> val2;
				ptrLCA = bstPtr.LCA(bstPtr.root, val1, val2);
				cout << "LCA is " << ptrLCA->data << endl;
				cin.get();
				break;
		case 9:    
				bstPtr.displayLevel(bstPtr.root, 1);
				break;
		case 10:    
				bool flag;
				flag = bstPtr.checkLeafLevel(bstPtr.root, 0, false);
				if (flag)
					cout << "Leaves are same" << endl;
				else
					cout << "not same" << endl;
				break;
		case 11:   
				int val;
				val = bstPtr.maxdistRoot(bstPtr.root, 0);
				cout << "Max distance to root: " << val << endl;
				break;
		case 12:   
				cout << "Enter the data to find the distance from root" << endl;
				int find;
				cin >> find;
				val = bstPtr.nodedistRoot(bstPtr.root, 0, find);
				cout << "Distance of " << find << " to root: " << val << endl;
				break;
		case 13:   
				int arr[1000];
				bstPtr.printPossiblePaths(bstPtr.root, arr, 0);
				break;
		case 14:
				bstPtr.bstToDLL(bstPtr.root);
				break;
		case 15:
				bstPtr.bstToDLLQueue(bstPtr.root);
				break;
		case 16:
				bstPtr.mirror(bstPtr.root);
				break;
		case 17:
				int diameterVal;
				diameterVal=bstPtr.diameter(bstPtr.root);
				cout << "Diameter is" << diameterVal << endl;
				break;
		case 18:
				int height;
				height = bstPtr.heightBST(bstPtr.root);
				cout << "height of BST "<< height << endl;
				break;
		case 19:
				bstPtr.deleteAllBST(bstPtr.root);
				break;
		case 20:
				cout << "Enter val to find the sum for possible paths in BST" << endl;
				int sumVal;
				cin >> sumVal;
				bstPtr.hasPathSum(bstPtr.root, sumVal,0);
				break;
		case 21:
			int findSuccVal;
			cout << "Enter the node to find its successor" << endl;
			cin >> findSuccVal;
			bstPtr.bstSuccessor(bstPtr.root,findSuccVal);
			break;
		case 22:
			cout << "Check if BST is height balanced" << endl;
			int heightBalanced,result;
			heightBalanced = 0;
			result=bstPtr.isBalanced(bstPtr.root, &heightBalanced);
			if (result)
				cout << "balanced" <<result<< endl;
			else
				cout << "not balanced" <<result<< endl;
			break;
		
		case 24:     exit(1);

		}
	}
}
void bst::display(node *temp, int level)
{
	if (temp != NULL)
	{
		display(temp->right, level + 1);
		cout << endl;
		if (temp == root)
		{
			cout << "Root->";
		}
		else
		{
			for (int i = 0; i<level; i++)
			{
				cout << "      ";
			}
		}
		cout << temp->data;
		cout << endl;
		display(temp->left, level + 1);
	}
}
void bst::displayLevel(node *temp_node, int level)
{
	queue<node *>q;
	if (root == NULL)
		cout << "empty" << endl;
	if (root)
		q.push(root);

	while (!q.empty())
	{
		node *temp = q.front();
		q.pop();
		cout << temp->data << endl;
		cin.get();
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}

}
void bst::printPossiblePaths(node *temp, int path[], int len)
{
	if (temp == NULL)
		return;

	node *tempPtr = new node;
	tempPtr = temp;

	path[len] = tempPtr->data;
	len++;


	if (tempPtr->left == NULL && tempPtr->left == NULL)
	{
		for (int i = 0; i<len; i++)
		{
			cout << path[i] << "   ";
		}
		cout << endl;
	}
	else
	{
		printPossiblePaths(tempPtr->left, path, len);
		printPossiblePaths(tempPtr->right, path, len);
	}

}
void bst::insert(node *temp, node *addNode)
{
	if (root == NULL)
	{
		//	root=new node;
		root = addNode;
		root->data = addNode->data;
		root->left = NULL;
		root->right = NULL;
		cout << "root node added" << root->data << endl;
		return;
	}

	if (temp->data > addNode->data)
	{
		if (temp->left == NULL)
		{
			cout << "temp->left is NULL" << endl;

			temp->left = addNode;
			temp->left->data = addNode->data;
			temp->left->left = NULL;
			temp->left->right = NULL;

		}
		else
		{
			cout << "temp->left is not NULL" << endl;

			insert(temp->left, addNode);
		}

	}
	else
	{
		if (temp->right == NULL)
		{
			cout << "temp->right is NULL" << endl;

			temp->right = addNode;
			temp->right->data = addNode->data;
			temp->right->left = NULL;
			temp->right->right = NULL;
		}
		else
		{
			insert(temp->right, addNode);
		}

	}

	return;
}
node* bst::find(node *temp, int item)
{
	node *ptr;
	if (root == NULL)
	{
		return NULL;
	}

	if (item > temp->data)
	{
		ptr = temp->right;
	}
	else
	{
		ptr = temp->left;
	}

	while (ptr != NULL)
	{
		if (item == ptr->data)
		{
		//	cout << "Item found" << ptr->data << endl;
			return ptr;
		}
		else
		{
			cout << "Item not found" << endl;
		//	return NULL;
		}

		if (item > ptr->data)
		{
			ptr = ptr->right;
		}
		else
		{
			ptr = ptr->left;
		}
	}
}
void bst::deleteNode(int item)
{

	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
	}

	node *parent;
	node *location;
	findDelNode(item, &parent, &location);
	cout << "delete" << parent->data << "location" << location->data << endl;

	if (location->left == NULL && location->right == NULL)
		case_a(location, parent);
	else if (location->right != NULL && location->left == NULL)
		case_b(location, parent);
	else if (location->left != NULL && location->right == NULL)
		case_b(location, parent);
	else
		case_c(location, parent);

}

void bst::findDelNode(int item, node **parent, node **location)
{
	node *ptr;
	node *ptrSave;
	if (root == NULL)
	{
		parent = NULL;
		location = NULL;
	}
	if (item == root->data)
	{
		*location = root;
		*parent = NULL;
	}
	if (item > root->data)
	{
		ptr = root->right;
	}
	else
	{
		ptr = root->left;
	}
	ptrSave = root;
	while (ptr != NULL)
	{
		if (item == ptr->data)
		{
			*location = ptr;
			*parent = ptrSave;
			return;
		}
		ptrSave = ptr;
		if (item > ptr->data)
		{
			ptr = ptr->right;
		}
		else
		{
			ptr = ptr->left;
		}
	}
	*location = NULL;
	*parent = ptrSave;
}
void bst::case_a(node *location, node *parent)
{
	cout << "casea" << location->data << endl;
	if (location == parent->left)
	{
		parent->left = NULL;
	}
	else
		parent->right = NULL;
}
void bst::case_b(node *location, node *parent)
{
	node *child;
	cout << "caseb" << location->data << parent->data << endl;
	if (location->left != NULL)
		child = location->left;
	else
		child = location->right;

	if (parent->left == location)
		parent->left = child;
	else
		parent->right = child;
}
void bst::case_c(node *location, node *parent)
{
	cout << "casec" << location->data << parent->data << endl;
	node *ptr;
	node *ptrParent=NULL;
	node *ptrMin, *ptrParentSave;
	ptr = location->right;

	while (ptr->left != NULL)
	{
		ptrParent = ptr;
		ptr = ptr->left;
	}
	ptrMin = ptr;
	ptrParentSave = ptrParent;
	//Swap the node to be deleted with the smallest node from the right subtree
	int temp;
	temp = location->data;
	location->data = ptrMin->data;
	ptrMin->data = temp;

	if (ptrMin->left == NULL && ptrMin->right == NULL)
		case_a(ptrMin, ptrParentSave);//Pass the node to be deleted and its parent
	else
		case_b(ptrMin, ptrParentSave);

	cout << "casec" << location->data << ptrMin->data << ptrParentSave->data << endl;
}

//Depth first search includes preOrder, inOrder and postOrder traversal
void bst::preOrder(node *ptr)//VLR
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
	}
	if (ptr != NULL)
	{
		cout << ptr->data << "   ";
		preOrder(ptr->left);
		preOrder(ptr->right);
	}

}
void bst::inOrder(node *ptr)//LVR
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
	}
	if (ptr != NULL)
	{
		inOrder(ptr->left);
		cout << ptr->data << "   ";
		inOrder(ptr->right);
	}
}
void bst::postOrder(node *ptr)//LRV
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
	}
	if (ptr != NULL)
	{
		postOrder(ptr->left);
		postOrder(ptr->right);
		cout << ptr->data << "   ";

	}
}
/*
Time complexity of below solution is O(h) where h is height of tree.
Also, the below solution requires O(h) extra space in function call stack for recursive function calls
*/
node* bst::LCA(node *rootNode, int val1, int val2)
{
	if (root == NULL)
	{
		cout << "Tree is empty for LCA" << endl;
		return root;
	}
	else
	{
		if (rootNode->data > val1 && rootNode->data > val2)
			return LCA(rootNode->left, val1, val2);
		if (rootNode->data < val1 && rootNode->data < val2)
			return LCA(rootNode->right, val1, val2);
		else
			return rootNode;

	}

}
bool bst::checkLeafLevel(node *bstTree, int currlevel, bool flag)
{
	bool leftval = true;
	bool rightval = true;;
	static int level = 0;

	if (bstTree->left == NULL && bstTree->right == NULL)
	{
		if (level == 0)
		{
			level = currlevel;
			return true;
		}
		else if (level == currlevel)
			return true;
		else
			return false;

	}
	if (bstTree->left)
		leftval = checkLeafLevel(bstTree->left, currlevel + 1, false);
	if (bstTree->right)
		rightval = checkLeafLevel(bstTree->right, currlevel + 1, false);

	if (!leftval || !rightval)
		return false;
	else
		return true;

}

int  bst::maxdistRoot(node *bstTree, int level)
{

	int leftVal = 0;
	int rightVal = 0;
	static int leafLevel = 0;
	if (bstTree->left == NULL && bstTree->right == NULL)
	{
		if (leafLevel == 0)
		{
			leafLevel = level;
			return leafLevel;
		}
		else if (leafLevel == level)
		{
			leafLevel = level;
			return leafLevel;
		}
		else if (leafLevel > level)
		{
			leafLevel = leafLevel;
			return leafLevel;
		}
		else
		{
			leafLevel = level;
			return leafLevel;
		}

	}

	if (bstTree->left)
		leftVal = maxdistRoot(bstTree->left, level + 1);
	if (bstTree->right)
		rightVal = maxdistRoot(bstTree->right, level + 1);

	if (leftVal > rightVal)
		return leftVal;
	else
		return rightVal;


}
int  bst::nodedistRoot(node *bstTree, int level, int finditem)
{
	int leftVal = 0;
	int rightVal = 0;
	static int leafLevel = 0;

	if (bstTree->left != NULL || bstTree->right != NULL)
	{
		if (bstTree->left->data == finditem || bstTree->right->data == finditem)
		{
			leafLevel = level + 1;
			return leafLevel;

		}
	}
	if (bstTree->left)
		leftVal = maxdistRoot(bstTree->left, level + 1);
	if (bstTree->right)
		rightVal = maxdistRoot(bstTree->right, level + 1);

	if (leftVal > rightVal)
		return leftVal;
	else
		return rightVal;
	
}
void bst::bstToDLL (node *bstTree)
{
	if (bstTree == NULL)
		return;
	
		node *DLLnode = bst::bstToDLLConvert(bstTree);
			
		while (DLLnode->left != NULL)
		{
			
			DLLnode = DLLnode->left;
		}
		while (DLLnode != NULL)
		{
			cout<<DLLnode->data<<" ";
			DLLnode = DLLnode->right;
		}

}
node* bst::bstToDLLConvert(node *bstTree)
{
	if (bstTree == NULL)
		return bstTree;
	
	if (bstTree->left != NULL)
	{
		node *tempLeft= bstToDLLConvert(bstTree->left);
		while (tempLeft->right != NULL)
		{
			tempLeft = tempLeft->right;
		}

		tempLeft->right = bstTree;
		bstTree->left = tempLeft;

	}
	if (bstTree->right != NULL)
	{
		node *tempRight = bstToDLLConvert(bstTree->right);
		while (tempRight->left != NULL)
		{
			tempRight = tempRight->left;
		}

		tempRight->left = bstTree;
		bstTree->right = tempRight;
	}
	return bstTree;
}
//convert to doubly linked list using BFS.
void  bst::bstToDLLQueue(node *bstTree)
{
	node *last = NULL;
	node *temp = NULL;

	queue<node *>q;
	if (root)
		q.push(root);

	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << temp->data << endl;
		cin.get();
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
		temp->left = last;
		temp->right = q.front();
		last = temp;
	}
	
}
void  bst::mirror(node *bstTree)
{

	if (bstTree ==NULL)
		return;
	else
	{
		node *temp = new node;

		mirror(bstTree->left);
		mirror(bstTree->right);
		temp = bstTree->left;
		bstTree->left = bstTree->right;
		bstTree->right= temp;
	}	
	
}
int  bst::heightBST(node *bstTree)
{
	if (bstTree==NULL)
		return 0;
	else
	{
		int lheight=heightBST(bstTree->left);
		int rheight = heightBST(bstTree->right);
		
		if (lheight > rheight)
			return lheight + 1;
		else
		return rheight + 1;
		//return (lheight > rheight) ? (lheight+1) : (rheight+1);

	}

//	return 1 + max(heightBST(bstTree->left), heightBST(bstTree->right));
}
int  bst::diameter(node *bstTree)
{
	if (bstTree == NULL)
		return 0;
	else
	{
		int lheight = heightBST(bstTree->left);
		int rheight = heightBST(bstTree->right);

		int ldiameter = diameter(bstTree->left);
		int rdiameter = diameter(bstTree->right);

		return max(lheight + rheight + 1, ldiameter + rdiameter);
	}
}
int  bst::isBalanced(node *bstTree, int *height)
{
	if (bstTree == NULL)
	{
		*height = 0;
		return 1;
	}
	/* lh --> Height of left subtree
	rh --> Height of right subtree */
	int lh = 0, rh = 0;
	int leftHt = isBalanced(bstTree->left,&lh);
	int rightHt = isBalanced(bstTree->right,&rh);

	*height = (lh > rh ? lh : rh) + 1;
		
	if ((lh - rh >= 2) || (rh - lh >= 2))
		return 0;//not balanced ie false
	else
		return leftHt&&rightHt;//balanced


}
void  bst::deleteAllBST(node *bstTree)
{

	if (bstTree == NULL)
		return;
	if (bstTree->left != NULL)
		deleteAllBST(bstTree->left);
	
	if (bstTree->right != NULL)
		deleteAllBST(bstTree->right);

		delete(bstTree);
}
void  bst::hasPathSum(node *bstTree,int val,int sumVal)
{
	
	if (bstTree == NULL)
		return ;
	
	sumVal = bstTree->data + sumVal;

	if (sumVal==val)
	{
		cout << "-----"<<sumVal << endl;

	}
	hasPathSum(bstTree->left, val, sumVal);
	hasPathSum(bstTree->right, val, sumVal);


}
void  bst::bstSuccessor(node *bstTree, int findVal)
{

	if (bstTree == NULL)
		return;
	node *foundNode = bst::find(bstTree, findVal);// find the node associate with findVal. Function find() is called.

	node *minNodeVal = new node;

	if (foundNode->right != NULL)//Once the node is found traverse to the right of the node to get the next highest element close to it.
	{
		minNodeVal = minNode(foundNode->right);
		cout <<"successor ..."<< minNodeVal->data << endl;
		return;
	}

	node *successor = NULL;
	while (bstTree != NULL)
	{
		if (foundNode->data < bstTree->data)
		{
			successor = bstTree;
			bstTree = bstTree->left;
		}
		else if (foundNode->data> bstTree->data)
		{			
			bstTree = bstTree->right;
		}
		else
			break;
	}
	cout<<"successor is "<< successor->data<<endl;
}
node *  bst::minNode(node *bstTree)
{
	node *curr = bstTree;
	while (curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}
/*static int topLevel=-1;//so that the value can be accessed even if you exist a function
if(flag)
topLevel=-1;
if(bstTree->left== NULL && bstTree->right==NULL)
{
if(topLevel==-1)
{
topLevel=currlevel;
return true;
}
if(topLevel==currlevel)
return true;
else
return false;

}

bool leftResult=true;
bool rightResult=true;

if(bstTree->left)
leftResult=checkLeafLevel(bstTree->left,currlevel+1,false);
if(bstTree->right)
rightResult=checkLeafLevel(bstTree->right,currlevel+1,false);

if(!leftResult || !rightResult)
return false;

return true;*/