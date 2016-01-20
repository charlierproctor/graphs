#include "graph.h"

using namespace std;

/**
 * @brief check to see whether two graphs have the same labeling AND edges
 *
 * @details ASSUMES that both graphs are the same type, have the same number of vertices, and have the same number of edges.
 *
 * @param a first graph
 * @param b second graph
 *
 * @return boolean: true if both graphs have the SAME labeling AND edges
 */
bool equivalent(Graph *a, Graph *b) {
	
	bool matched;
	
	// check all a edges
	for (Edge *edge_a : a->edges) {
		
		matched = false;

		// looking for a matching edge in b's edges
		for (Edge *edge_b : b->edges) {
			if (*edge_a == *edge_b) {
				matched = true;
				break;
			}	
		}
		
		// no match -> return false.
		if (!matched) {
			return false;
		}
	}

	// matched all the edges
	return true;
}

bool compare(const Node *a, const Node *b) {
	return a->index < b->index;
}

bool Graph::isomorphic(Graph *g) {
	
	// different number of vertices
	if (this->vertices.size() != g->vertices.size()) {
		return false;
	
	// different number of edges
	} else if (this->edges.size() != g->edges.size()) {
		return false;

	// different graph types
	} else if (this->type != g->type) {
		return false;
	}

	int numVertices = this->vertices.size();

	// index g's vertices (so we can permute them)
	int i = 0;
	for (auto elem: g->vertices) {
		elem.second->index = i++;
	}

	// create an array of g's vertices
	Node **vertices = new Node *[numVertices];
	int j = 0;
	for (auto elem : g->vertices) {
		vertices[j++] = elem.second;
	}

	// permute the vertices
	do {
		// label this array permutation sequentially
		for (int label = 0; label < numVertices; label++) {
			vertices[label]->label = label;
		}

		// if we have a match... return true
		if (equivalent(this,g)) {
			return true;
		}
	} while (next_permutation(vertices, vertices + i, compare));

	return false;

}
