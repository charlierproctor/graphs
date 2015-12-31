#include "complete.h"

using namespace std;

CompleteGraph::CompleteGraph(int size, string _name, graph_t _type) : Graph(_name,_type) {
	
	// create the vertices
	for (int i = 0; i < size; ++i) {
		createVertex();
	}

	// connect each vertex to every other vertex
	for (Node *from : vertices) {
		for (Node *to : vertices) {
			if (from != to) {
				from->connect(to, DIRECTED);
			}
		}
	}

}

CompleteGraph::~CompleteGraph(){

}
