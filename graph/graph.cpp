/*
Undirected graph have symmetrical relationship for example relationship used in social networks like linkedIn, facebook.They are bidirectional.
Directed graph can be used for page links
weighted graph can be used for airline companies.
*/
/*
This is a directed graph.Commented version in addEdge() consists of code for undirected graph.
1. Enter node in graph
2. Depth First Search
3. Breadth First Search
*/
#include<iostream>
#include<queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct node
{
	int data;
	node *next;
};

class graphClass
{
public:
	graphClass();
	node *newNode(int data);
	void addEdge(node **graphNode, int from, int to);
	node** createGraph(int elements);
	void printGraph(node **graphNode, int elements);
	bool reachableBFS(int from, int to, int reached[], node **graphNode);
	int* bfs(int from, int reached[], node **graphNode);
	bool reachableDFS(int from, int to, int reached[], node **graphNode);
	int* dfs(int start, int reached[], node **graphNode);
	void cloneGraph(node **graphNode,int elements);
};
graphClass::graphClass()
{

}
node* graphClass::newNode(int data)
{
	node *nodePtr = new node;
	nodePtr->data = data;
	nodePtr->next = NULL;
	return nodePtr;
}
void graphClass::printGraph(node **graphNode, int elements)
{
	for (int i = 0; i<elements; ++i)
	{
		node *nodePtr = graphNode[i];
		cout << "\n Adjacency list of vertex \n head " << i << endl;
		while (nodePtr)
		{
			cout << "->" << nodePtr->data;
			nodePtr = nodePtr->next;
		}
		cout << endl;
		cin.get();
	}
}
void graphClass::addEdge(node **graphNode, int from, int to)
{
	node *newNode = graphClass::newNode(to);
	if (graphNode[0] == NULL)
	{

		newNode->data = to;
		newNode->next = graphNode[from];
		graphNode[from] = newNode;
	}
	else
	{
		newNode->data = to;
		newNode->next = graphNode[from];
		graphNode[from] = newNode;
	}
	/* This logic is for undirected graph
	newNode = graphClass::newNode(from);
	newNode->next = graphNode[to];
	graphNode[to] = newNode;*/

}
bool graphClass::reachableDFS(int from, int to, int reached[], node **graphNode)
{
	int *reachedQueue = dfs(from, reached, graphNode);
	cout << from << to << endl;
	cin.get();
	return reached[to];
}
int* graphClass::dfs(int start, int reached[], node **graphNode)
{
	node *current = graphNode[start];
	reached[start] = 1;
	while (current != NULL)
	{
			if (reached[current->data] == 0)
			dfs(current->data, reached, graphNode);

		current = current->next;
	}

	return reached;

}
bool graphClass::reachableBFS(int from, int to, int reached[], node **graphNode)
{
	int *reachedQueue = bfs(from, reached, graphNode);
	cin.get();
	return reached[to];
}
int* graphClass::bfs(int start, int reached[], node **graphNode)
{
	queue<int>q;
	q.push(start);
	reached[start] = 1;
	int current;
	while (!q.empty())
	{
		node *nodePtr = new node;
		current = q.front();
		nodePtr = graphNode[current];
		q.pop();
		while (nodePtr != NULL)
		{
			if (reached[nodePtr->data] == 0)
				q.push(nodePtr->data);

			reached[nodePtr->data] = 1;

			nodePtr = nodePtr->next;
		}

	}
	return reached;
}
int main()
{
	int elements;
	graphClass *graphClassPtr = new graphClass();
	cout << "Enter how many elements to enter in graph" << endl;
	cin >> elements;


	node **graphNode = new node*[elements];//dynamically create an array of pointers
	int *reached = new int[elements];
	for (int i = 0; i<elements; i++)
	{
		graphNode[i] = NULL;
		reached[i] = 0;//initialize the flag for all the elements in graph	to 0 ie false;

	}

	/*graphClassPtr->addEdge(graphNode, 3, 5);
	graphClassPtr->addEdge(graphNode, 5, 7);
	graphClassPtr->addEdge(graphNode, 7, 2);
	graphClassPtr->addEdge(graphNode, 2, 1);
	graphClassPtr->addEdge(graphNode, 4, 2);
	graphClassPtr->addEdge(graphNode, 9, 2);
	graphClassPtr->addEdge(graphNode, 2, 8);*/

	graphClassPtr->addEdge(graphNode, 0, 1);
	graphClassPtr->addEdge(graphNode, 0, 4);
	graphClassPtr->addEdge(graphNode, 1, 2);
	graphClassPtr->addEdge(graphNode, 1, 3);
	graphClassPtr->addEdge(graphNode, 1, 4);
	graphClassPtr->addEdge(graphNode, 2, 3);
	graphClassPtr->addEdge(graphNode, 3, 4);
	graphClassPtr->printGraph(graphNode, elements);

//	int flag = graphClassPtr->reachableBFS(0, 2, reached, graphNode);
	//int flag=graphClassPtr->reachableBFS(2,4,reached,graphNode);
	int flag = graphClassPtr->reachableDFS(0, 1, reached, graphNode);
	if (flag)//if(1)then true
		cout << "true-->reachable";
	else
		cout << "false-->not reachable";
	cin.get();
}