
#include<iostream>
#include<queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node
{
	int data;

	std::vector<Node *> neighbors;
};

typedef std::unordered_map<Node *,Node *> Map;
Map map;

Node * cloneDFS(Node *graph, Node *graphCopy)
{
	if (!graph) return NULL;

	Map map;
	queue<Node *> q;
	q.push(graph);

	Node *gc = new Node;
	map[graph] = gc;

	while (!q.empty()) {
		Node *node = q.front();
		q.pop();
		int n = node->neighbors.size();
		for (int i = 0; i < n; i++) {
			Node *neighbor = node->neighbors[i];
			// no copy exists
			if (map.find(neighbor) == map.end())
			{
				Node *p = new Node();
				map[node]->neighbors.push_back(p);
				map[neighbor] = p;
				q.push(neighbor);
				cout << "nooooooo" << q.front()->data<<endl;
				cin.get();

			}
			else {     // a copy already exists
				map[node]->neighbors.push_back(map[neighbor]);
				cout << "a copy already exists" << map[node]->data << endl;
				cin.get();

			}
		}
	}

	return gc;
}

int main()
{
	Node* n1 = new Node();
	n1->data = 1;
	Node* n2 = new Node();
	n2->data = 1;
	Node* n3 = new Node();
	n3->data = 3;
	n1->neighbors.push_back(n2);
	n1->neighbors.push_back(n1);//to test for cycle

	n1->neighbors.push_back(n3);

	Node* copy = new Node();
	cloneDFS(n1, copy);

	return 0;
}