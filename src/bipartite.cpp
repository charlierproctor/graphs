#include "graphs.h"

using namespace std;

CompleteBipartiteGraph::CompleteBipartiteGraph(int n, int m, string _name, graph_t _type) : Graph(_name,_type) {

	vector<Node *> n_vertices;
	vector<Node *> m_vertices;

	// create the n vertices
	for (int i = 0; i < n; ++i) {
		Node *vertex = createVertex();
		n_vertices.push_back(vertex);
	}
	
	// create the m vertices
	for (int i = 0; i < m; ++i) {
		Node *vertex = createVertex();
		m_vertices.push_back(vertex);
	}

	// connect each vertex to every other vertex
	for (Node *from : n_vertices) {
		for (Node *to : m_vertices) {
			createEdge(from, to, _type);
		}
	}

}

CompleteBipartiteGraph::~CompleteBipartiteGraph(){

}
