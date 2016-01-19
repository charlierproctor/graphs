#include "graph.h"

using namespace std;

/**
 * @brief check to see whether two graphs have the same labeling AND edges
 *
 * @param a first graph
 * @param b second graph
 *
 * @return boolean: true if both graphs have the SAME labeling AND edges
 */
bool equivalent(Graph *a, Graph *b) {
	
	graph_t type;

	// different number of vertices
	if (a->vertices.size() != b->vertices.size()) {
		return false;
	
	// different number of edges
	} else if (a->edges.size() != b->edges.size()) {
		return false;

	// different graph types
	} else if ((type = a->type) != b->type) {
		return false;
	}
	

	bool matched;
	// check all a edges
	for (Edge *edge_a : a->edges) {
		
		matched = false;

		// looking for a matching edge in b's edges
		for (Edge *edge_b : b->edges) {
			if ((edge_a->from->temp_label == edge_b->from->temp_label)
				&& (edge_a->to->temp_label == edge_b->to->temp_label)) {
				matched = true;
				break;
			} else if ((type == UNDIRECTED) && ((edge_a->to->temp_label == edge_b->from->temp_label)
				&& (edge_a->from->temp_label == edge_b->to->temp_label))) {
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
	return a->label < b->label;
}

bool Graph::isomorphic(Graph *g) {

	int numVertices = this->vertices.size();

	// label all THIS graph's vertices consequetively
	int label = 0;
	for (auto elem: this->vertices) {
		elem.second->temp_label = label++;
	}

	// label all g's vertices consequetively
	label = 0;
	for (auto elem: g->vertices) {
		elem.second->temp_label = label++;
	}

	// create an array of g's vertices
	Node **vertices = new Node *[numVertices];
	int i = 0;
	for (auto elem : g->vertices) {
		vertices[i++] = elem.second;
	}

	// sort before permutation!
	sort(vertices, vertices + i, compare);

	// permute the vertices
	do {
		// label this array permutation sequentially
		for (label = 0; label < numVertices; label++) {
			vertices[label]->temp_label = label;
		}

		// if we have a match... return true
		if (equivalent(this,g)) {
			return true;
		}
	} while (next_permutation(vertices, vertices + i, compare));

	return false;

}
