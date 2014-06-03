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
22. Find the nearest ceiling for a given number
23. Find the next minmum node in a tree from the given node
24. Check if bst is height balanced
25. Count Number of Binary Search Tress given N Distinct Elements
26. Size of Binary Search Tree

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
	bool checkLeafLevel(node *rootNode, int currlevel);
	//Depth first traversal for bst includes preOder,inOrder and postOrders
	void preOrder(node * root);//it works based on VLR
	void inOrder(node * root);//it works based on LVR
	void postOrder(node * root);//it works based on LRV
	int diameter(node * root);
	void hasPathSum(node * root,int val,int sumVal);
	void deleteAllBST(node * root);
	node *minNode(node *root);
	void bstSuccessor(node *root, int findSuccVal);
	void inorderSuccessor(int *flag, struct node *root, int key, node *parent);
	void ceilNode(node *root, int num,int foundVal);
	int isBalanced(node *root, int *height);
	int countBST(int number);
	int sizeBST(node *root);
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
	    cout << "22. Find the nearest ceiling for a given number" << endl;
		cout << "23. Find a minimum node to a given node" << endl;
		cout << "24. Check if BST is height balanced" << endl;
		cout << "25. Count # of BST for given N Distinct Elements" << endl;
		cout << "26. Size of Binary Search Tree" << endl;

		cout << "27. Quit" << endl;

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
				if (findElementNode!=NULL)
				cout << "Item found " << findElementNode->data << endl;
				else
					cout << "Item not found " << endl;

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
				flag = bstPtr.checkLeafLevel(bstPtr.root, 0);
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
				if (val < 0)
					cout << "Item not found" << endl;
				else
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
				{int findSuccVal;
				int succFlag = 0;
				node *parent = new node;
		

				cout << "Enter the node to find its successor" << endl;
				cin >> findSuccVal;
				//	bstPtr.bstSuccessor(bstPtr.root,findSuccVal);
				bstPtr.inorderSuccessor(&succFlag, bstPtr.root, findSuccVal,parent);
				break; }
		case 22:
				{
					int ceilNum;
					int foundVal = 0;
					cout << "Enter the ceiling for a number" << endl;
					cin >> ceilNum;
		
					bstPtr.ceilNode(bstPtr.root, ceilNum, foundVal);
					break; 
		       }
		case 23:
				{int minNodeVal;
				node *foundNode;
				cout << "Enter the node to find its next minimum node" << endl;
				cin >> minNodeVal;
				foundNode=bstPtr.find(bstPtr.root, minNodeVal);

				foundNode = bstPtr.minNode(foundNode);
				cout << "Next minimum node is : " << foundNode->data << endl;
				break;
				}
		case 24:
			cout << "Check if BST is height balanced" << endl;
			int heightBalanced,result;
			heightBalanced = 0;
			result=bstPtr.isBalanced(bstPtr.root, &heightBalanced);
			if (result)//ie if true or if (1)
				cout << "balanced" <<result<< endl;
			else
				cout << "not balanced" <<result<< endl;
			break;
		case 25:
			int number, countNo;
			cout << "Enter number to count # of BST" << endl;
			cin >> number;
			countNo = bstPtr.countBST(number);
			
			cout << "Number of BST's : " << countNo << endl;
			break;
		case 26:
			int size;
			size = bstPtr.sizeBST(bstPtr.root);

			cout << "Size of BST's : " << size << endl;
			break;
		
		case 27:     exit(1);

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
		//cin.get();
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


	if (tempPtr->left == NULL && tempPtr->right == NULL)
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
		

		else if (item > ptr->data)
		{
			ptr = ptr->right;
		}
		else if (item < ptr->data)
		{
			ptr = ptr->left;
		}
		else
		{
			cout << "Item not found" << endl;
		   return NULL;
		}
	}
	return ptr;

  /* can also be done this way	
    if (temp != NULL)
	{
		if (temp->data == item)
		{
			cout << "item found----" << item << endl;
			return temp;
		}
		else if (temp->data > item)
			find(temp->left, item);
		else if (temp->data < item)
			find(temp->right, item);
		
	}
	else
	{
	   cout << "item not found" << endl;
		return NULL;
	}*/
}	
void bst::deleteNode(int item)
{

	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}

	node *parent;
	node *location;
	findDelNode(item, &parent, &location);
	//cout << "delete" << parent->data << "location" << location->data << endl;

	if (location != NULL)
	{

		if (location->left == NULL && location->right == NULL)
			case_a(location, parent);
		else if (location->right != NULL && location->left == NULL)
			case_b(location, parent);
		else if (location->left != NULL && location->right == NULL)
			case_b(location, parent);
		else
			case_c(location, parent);
	}
	else
	{
		cout << "Item to be deleted was not found" << endl;
	}

}

void bst::findDelNode(int item, node **parent, node **location)
{
	node *ptr=NULL;
	node *ptrSave;
	*location = NULL;
	
	if (item == root->data)//item to be deleted is root
	{
		*location = root;
		*parent = NULL;
		return;
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
	
	//*parent = ptrSave;
}
void bst::case_a(node *location, node *parent)
{
	cout << "casea" << location->data << endl;
	if (parent != NULL)
	{

		if (location == parent->left)
		{
			parent->left = NULL;
		}
		else
			parent->right = NULL;
	}
	else
	{
		root = NULL;
	}
}
void bst::case_b(node *location, node *parent)
{
	node *child;
//	cout << "caseb" << location->data << parent->data << endl;
	if (location->left != NULL)
		child = location->left;
	else
		child = location->right;
	if (parent != NULL)
	{

		if (parent->left == location)
			parent->left = child;
		else
			parent->right = child;
	}
	else
	{
		root = child;
	}
}
void bst::case_c(node *location, node *parent)
{
	//cout << "casec" << location->data << parent->data << endl;
	node *ptr;
	node *ptrParent=NULL;
	node *ptrMin;

	ptr = location->right;
	while (ptr->left != NULL)
	{
		ptrParent = ptr;
		ptr = ptr->left;
	}
	ptrMin = ptr;
	

	//Swap the node to be deleted with the smallest node from the right subtree
	int temp;
	temp = location->data;
	location->data = ptrMin->data;
	ptrMin->data = temp;

	if (ptrParent == NULL)
		
		ptrParent = location;

	if (ptrMin->left == NULL && ptrMin->right == NULL)
		case_a(ptrMin, ptrParent);//Pass the node to be deleted and its parent
	else
		case_b(ptrMin, ptrParent);

//	cout << "casec" << location->data << ptrMin->data << ptrParentSave->data << endl;
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
void bst::inOrder(node *ptr)//LVR..it displays the bst in sorted order.O(n) n=#of nodes because we visit each nodes exactly once, so time taken is porportional to number of nodes in tree.
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
bool bst::checkLeafLevel(node *bstTree, int currlevel)
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
		leftval = checkLeafLevel(bstTree->left, currlevel + 1);
	if (bstTree->right)
		rightval = checkLeafLevel(bstTree->right, currlevel + 1);//0 is false and 1 is true
	

	if (leftval &&  rightval)
		return true;
	else
		return false;
	/*
	if (!leftval || !rightval)
		return false;
	else
		return true;*/

}

int  bst::maxdistRoot(node *bstTree, int level)//this is equal to finding the depth of a node from the root.
{//height of tree:Max # of edges from the root to the leaf.If the tree has only root node, then it is the leaf node as well. Hencce, height is 0. max(leftHt,rightHt)+1.
 //depth of leaf node: Max #of edges from the root to the leaf.If the tree has only root node, then it is the leaf node as well.Hencce, depth is 0.

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
	int leafLevel = level;
	int depth=0;
	
	while (bstTree != NULL)
	{

		if (bstTree->data > finditem && bstTree->left!=NULL)
		{
			bstTree = bstTree->left;
			leafLevel++;
		}
		else if (bstTree->data < finditem && bstTree->right!=NULL)
		{
			bstTree = bstTree->right;
			leafLevel++;

		}
		else if (bstTree->data == finditem)
		{
			return leafLevel;
		}
		else
			return -1;
	}
	
	// recursion
	/*if (bstTree == NULL)
		return -1;
	if (bstTree->data == finditem)
		return level;

	 depth= nodedistRoot(bstTree->left, level + 1, finditem);
	 if (depth > 0)
		 return depth;
	return nodedistRoot(bstTree->right, level + 1, finditem);
	*/
	
}
int   bst::sizeBST(node *bstTree)//size of BST= #of nodes in BST
{
	if (bstTree == NULL)
		return 0;
	else
	{
		int leftSize=sizeBST(bstTree->left);
		int rightSize = sizeBST(bstTree->right);
		return leftSize + rightSize + 1;
	}
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
		temp->left = last;//left is equivalent to next pointer in DLL
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
int  bst::heightBST(node *bstTree)//height of a tree is number of max edges from root to the leaf nodes
{
//height of tree:Max # of edges from the root to the leaf.If the tree has only root node, then it is the leaf node as well. Hencce, height is 0. max(leftHt,rightHt)+1.
//If height is calculated based on node count, then height is 1 for the tree with only root node.
//depth of leaf node: Max #of edges from the root to the leaf.If the tree has only root node, then it is the leaf node as well.Hencce, depth is 0.

  if (bstTree==NULL)
		return -1;
	else
	{
		int lheight=heightBST(bstTree->left);
		int rheight = heightBST(bstTree->right);
		
		if (lheight > rheight)
			return lheight + 1;
		else
		return rheight + 1;
		
		//return max(lheight, rheight) + 1;
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
	rh --> Height of right subtree 
	Get the heights of left and right subtrees in lh and rh 
    And store the returned values in leftHt and rightHt
	*/
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
void bst::inorderSuccessor(int *flag,node *root, int num,node *prev)
{//this code will give the nearest successor. So you want to find the nearest successor for a max node, this code will give the nearest successor
	int val = *flag;

	if (root == NULL)
		return;
	inorderSuccessor(&*flag, root->left,num,prev);
	if (root->data == num)
	{
		val = 1;
		cout << "fff" << root->data<<"----" << *flag<<"---" << &flag<<"---"<<&*flag<<" ----"<<prev->data << endl;

	}
	else if (val == 0) //if val is 0, 0 is false
	{
		prev = root;
		cout << root->data << endl;
			
	}
	inorderSuccessor(&*flag, root->right, num,prev);
	
}
void bst::ceilNode(node *root, int num,int foundVal)
{	//node with maximum value will not have successor or a node closest to it which is smaller than it.
	if (root != NULL)
	{
		if (num >= root->data)
			ceilNode(root->right, num, foundVal);
		else
			ceilNode(root->left, num, root->data);

	}
	else if (foundVal > 0)
		cout << "Ceil " << foundVal<<endl;
	else
		cout << " No Ceil " << foundVal << endl;

}
void  bst::bstSuccessor(node *bstTree, int findVal)
{//node with maximum value will not have successor

	if (bstTree == NULL)
		return;
	node *foundNode = bst::find(bstTree, findVal);// find the node associate with findVal. Function find() is called. O(h), where h is height=log2N where n is #of nodes.
	
	node *minNodeVal = new node;

	if (foundNode->right != NULL)//Once the node is found traverse to the right of the node to get the next highest element close to it.
	{
		minNodeVal = minNode(foundNode->right);
		cout <<"successor ..."<< minNodeVal->data << endl;
		return;
	}

	node *successor = NULL;
	node * ancestor = bstTree;
	while (ancestor != foundNode)
	{
		if (foundNode->data <= ancestor->data)
		{
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else 
		{
			ancestor = ancestor->right;
		}
	
	}
	if (successor!=NULL)
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
int  bst::countBST(int number)
{
	
	if (number == 0 || number == 1)
		return 1;
	else
	{
		int sum = 0;
		int left=0, right=0;
		for (int i = 1; i <= number; i++)
		{
			left = countBST(i - 1);
			right = countBST(number - i);
			sum += left*right;
		}
		return sum;
	}
}