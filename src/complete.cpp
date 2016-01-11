#include "graph_types.h"

using namespace std;

CompleteGraph::CompleteGraph(int size, string _name, graph_t _type) : Graph(_name,_type) {
	
	// create the vertices
	for (int i = 0; i < size; ++i) {
		createVertex();
	}

	// connect each vertex to every other vertex
	for (auto from : vertices) {
		for (auto to : vertices) {
			if (type == UNDIRECTED ? to.second->label > from.second->label : from.second->label != to.second->label) {
				createEdge(from.second, to.second, type);
			}
		}
	}

}

CompleteGraph::~CompleteGraph(){

}
