#include "graphs.h"

using namespace std;

PathGraph::PathGraph(int size, string _name, graph_t _type) : Graph(_name,_type) {
	
	// create the vertices
	for (int i = 0; i < size; ++i) {
		createVertex();
	}

	// connect each vertex to the next vertex
	for (std::map<int,Node *>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		if (next(it) != vertices.end()) {
			createEdge((*it).second, (*(next(it))).second,type);
		}
	}

}

