#include "graph.h"

using namespace std;

bool Graph::isConnected(){

	// a graph without vertices is connected
	if (vertices.size() == 0) {
		return true;
	}

	// start at the first vertex
	stack<Node *> s;
	s.push(vertices[0]);

	// use a depth-first traversal to mark all nodes reachable as visited
	Node *cursor;
	while (!s.empty()){

		// pop off the top element
		cursor = s.top();
		s.pop();
		
		// mark this node as visited
		cursor->visited = true;

		// push on all adjacent nodes
		for (Node *adj : cursor->adj_nodes) {
			s.push(adj);
		}
	}

	// check to see that all the nodes were visited
	for (auto elem : vertices) {
		if (!elem.second->visited) {
			return false;
		}
	}

	return true;
}
