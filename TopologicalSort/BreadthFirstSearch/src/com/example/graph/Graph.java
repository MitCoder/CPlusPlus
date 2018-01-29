package com.example.graph;

import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Queue;
/*	BFS and DFS with adjacent list. BFS is used to search a item in the shortest path possible.
 * DFS is used to avoid any cycles and to find an item if the graph has depth.
*/

public class Graph {

	List<Integer> adjacentList[];
	int totalVertices;

	Graph(int totalVertices) {
		this.totalVertices = totalVertices;
		adjacentList = new LinkedList[totalVertices];

		for (int i = 0; i < totalVertices; i++) {
			adjacentList[i] = new LinkedList<Integer>();
		}

	}

	// add an edge to the vertex with adjacent list
	private void addEdge(int vertex, int u) {
		adjacentList[vertex].add(u);
		System.out.println(adjacentList[vertex]);

	}

	private void printGraph() {
		System.out.println("Printing");
		for (int i = 0; i < totalVertices; i++) {
			System.out.println(adjacentList[i]);
		}
	}

	private void dfsReached(int from, boolean visited[]) {

		visited[from] = true;
		System.out.println("Item visited" + from);
		ListIterator<Integer> items = adjacentList[from].listIterator();

		while (items.hasNext()) {

			int nextItem = items.next();
			if (!visited[nextItem]) {
				visited[nextItem] = true;
				dfsReached(nextItem, visited);
			}
		}
	}

	private void dfs(int from) {

		boolean visited[] = new boolean[totalVertices];

		dfsReached(from, visited);

	}

	private void bfs(int from, int to) {

		System.out.println("BFS");
		int counter = 0;
		boolean visited[] = new boolean[totalVertices];

		if (adjacentList == null)
			return;

		Queue<Integer> queue = new LinkedList<Integer>();
		queue.offer(from);

		visited[from] = true;

		if (!queue.isEmpty()) {
			int current = queue.poll();
			System.out.println("queue item" + current);
			ListIterator<Integer> nextItem = adjacentList[current].listIterator();

			while (nextItem.hasNext()) {
				int item = nextItem.next();
				if (!visited[item]) {
					visited[item] = true;

					queue.offer(item);
					counter++;
					System.out.println("queue item" + item);

				}

			}
		}
		System.out.println(visited[to]);
		System.out.println(counter);

	}

	public static void main(String args[]) {
		Graph g = new Graph(4);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(1, 3);
		g.addEdge(3, 3);

		g.printGraph();

		//g.bfs(0, 2);
		g.dfs(2);

	}

}
