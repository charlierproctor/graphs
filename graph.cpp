#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(string _name){
	name = _name;
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

	return num;
}

void Graph::dot(){
	
	cout << "digraph " << name << " { " << endl;

	// iterate through all the vertices
	for (Node *from : vertices) { 
		for (Node *to : from->adj_nodes){
			cout << "\"" << from->label << "\" -> \"" << to->label << "\";" << endl;
		}
	}

	cout << "}" << endl;
	
}
