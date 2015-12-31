#include "graph.h"

using namespace std;

Graph::Graph(string _name, graph_t _type){
	name = _name;
	type = _type;
}

Graph::~Graph(){

}

Node *Graph::createVertex(){
	Node *elem = new Node(numVertices());
	vertices.push_back(elem);
	return elem;
}

int Graph::numVertices(){
	return vertices.size();
}

int Graph::numEdges(){
	int num = 0;
	
	// iterate through all the vertices
	for (Node *elem : vertices) {
		// summing the number of adjacent nodes
		num += elem->adj_nodes.size();
	}

	// divide by two if undirected
	return (type == UNDIRECTED ? num / 2 : num);
}

void Graph::dot(){

	if (type == UNDIRECTED) {
		cout << "graph " << name << " { " << endl;
	} else {
		cout << "digraph " << name << " { " << endl;
	}

	string connector = (type == UNDIRECTED ? "--" : "->");

	// iterate through all the vertices
	for (Node *from : vertices) { 
		for (Node *to : from->adj_nodes){
			cout << "\"" << from->label << "\" " << connector << " \"" << to->label << "\";" << endl;
		}
	}

	cout << "}" << endl;
	
}
