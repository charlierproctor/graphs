#include "graph.h"

using namespace std;

Graph::Graph(string _name, graph_t _type){
	name = _name;
	type = _type;
}

Graph::~Graph(){

}

Node *Graph::createVertex(){
	int label = vertices.size();
	Node *elem = new Node(label);
	vertices[label] = elem;
	return elem;
}

Edge *Graph::createEdge(Node *from, Node *to, graph_t type){
	Edge *edge = new Edge();
	
	// set the attributes
	edge->to = to;
	edge->from = from;
	edge->type = type;

	// add this edge to our set
	edges.insert(edge);

	// and connect the two with pointers.
	from->connect(to, type);

	return edge;

}

void Graph::dot(){

	if (type == UNDIRECTED) {
		cout << "graph " << name << " { " << endl;
	} else {
		cout << "digraph " << name << " { " << endl;
	}

	string connector = (type == UNDIRECTED ? "--" : "->");

	// iterate through all the edges
	for (Edge *edge : edges) {
		cout << "\"" << edge->from->label << "\" " << connector << " \"" << edge->to->label << "\";" << endl;
	}

	cout << "}" << endl;
	
}
