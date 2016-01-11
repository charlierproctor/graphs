#include "search.h"

using namespace std;

Node *bfs(Node *start, Node *find) {
	queue<Node *> q;
	
	// push on the first element
	q.push(start);

	Node *cursor;
	while (!q.empty()) {
		
		// pop off the front element
		cursor = q.front();
		q.pop();

		/// we found the node we're looking for	
		if (cursor == find) {
			return cursor;
		}
		
		// push all adjacent nodes onto the queue
		for (Node *adj : cursor->adj_nodes) {
			q.push(adj);
		}
	}

	// didn't find the element
	return NULL;

}

Node *dfs(Node *start, Node *find) {
	stack<Node *> s;
	
	// push on the first element
	s.push(start);

	Node *cursor;
	while (!s.empty()) {
		
		// pop off the top element
		cursor = s.top();
		s.pop();

		/// we found the node we're looking for	
		if (cursor == find) {
			return cursor;
		}
		
		// push all adjacent nodes onto the queue
		for (Node *adj : cursor->adj_nodes) {
			s.push(adj);
		}
	}

	// didn't find the element
	return NULL;

}
