#include "search.h"

using namespace std;

Node *bfs(Node *start, int find) {
	queue<Node *> q;
	
	// push on the first element
	q.push(start);

	Node *cursor;
	while (!q.empty()) {
		
		// pop off the front element
		cursor = q.front();
		q.pop();

		/// we found the node we're looking for	
		if (cursor->label == find) {
			return cursor;
		}
		
		// push all adjacent nodes onto the queue
		for (auto adj : cursor->adj_nodes) {
			q.push(adj.second);
		}
	}

	// didn't find the element
	return NULL;

}

Node *dfs(Node *start, int find) {
	stack<Node *> s;
	
	// push on the first element
	s.push(start);

	Node *cursor;
	while (!s.empty()) {
		
		// pop off the top element
		cursor = s.top();
		s.pop();

		/// we found the node we're looking for	
		if (cursor->label == find) {
			return cursor;
		}
		
		// push all adjacent nodes onto the queue
		for (auto adj : cursor->adj_nodes) {
			s.push(adj.second);
		}
	}

	// didn't find the element
	return NULL;

}
