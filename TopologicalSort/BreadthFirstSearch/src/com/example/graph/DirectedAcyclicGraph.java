package com.example.graph;

import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Stack;

/**
 * Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of
 * vertices such that for every directed edge uv, vertex u comes before v in the
 * ordering. Topological Sorting for a graph is not possible if the graph is not
 * a DAG
 */

public class DirectedAcyclicGraph {

	LinkedList<Integer> adjacentList[];
	int totalElements;

	DirectedAcyclicGraph(int totalElements) {
		this.totalElements = totalElements;
		adjacentList = new LinkedList[totalElements];

		for (int i = 0; i < totalElements; i++) {

			adjacentList[i] = new LinkedList<Integer>();

		}

	}

	private void TopologicalSort() {

		Stack<Integer> stack = new Stack<Integer>();
		boolean visited[] = new boolean[totalElements];

		for (int i = 0; i < totalElements; i++) {
			visited[i] = false;
		}

		for (int i = 0; i < totalElements; i++) {
			if (visited[i] == false) {

				TopologicalSortUtil(i, visited, stack);

			}
		}

		while (!stack.empty()) {
			int item = stack.pop();
			System.out.println(item);
		}

	}

	private void TopologicalSortUtil(int vertex, boolean[] visited, Stack stack) {
		visited[vertex] = true;
		ListIterator<Integer> item = adjacentList[vertex].listIterator();

		while (item.hasNext()) {
			int nextItem = item.next();
			if (!visited[nextItem]) {

				TopologicalSortUtil(nextItem, visited, stack);
			}

		}
		stack.push(vertex);

	}

	private void addEdge(int vertex, int u) {
		adjacentList[vertex].add(u);

	}

	private void printGraph() {

		for (int i = 0; i < totalElements; i++) {

			System.out.println(adjacentList[i]);

		}
	}

	public static void main(String args[]) {
		DirectedAcyclicGraph g = new DirectedAcyclicGraph(6);
		g.addEdge(5, 2);
		g.addEdge(5, 0);
		g.addEdge(4, 0);
		g.addEdge(4, 1);
		g.addEdge(2, 3);
		g.addEdge(3, 1);

		g.TopologicalSort();
	}

}
