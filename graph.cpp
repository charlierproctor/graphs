#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(){

}

Graph::~Graph(){

}

Node *Graph::createVertex(int label){
	Node *elem = new Node(label);
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
