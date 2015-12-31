#include "node.h"

using namespace std;

Node::Node(int _label){
	label = _label;
}

Node::~Node(){
}

void Node::connect(Node* elem, graph_t type){
	adj_nodes.push_back(elem);
	if (type == UNDIRECTED){
		elem->connect(this, DIRECTED);
	}
}
