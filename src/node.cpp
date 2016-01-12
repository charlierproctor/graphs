#include "graph.h"

using namespace std;

Node::Node(int _label){
	label = _label;
	visited = false;
}

void Node::connect(Node* elem, graph_t type){
	adj_nodes.insert(elem);
	if (type == UNDIRECTED){
		elem->connect(this, DIRECTED);
	}
}
