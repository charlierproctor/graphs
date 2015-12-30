#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(){

}

Node *Graph::createVertex(int label){
	Node *elem = new Node(label);
	vertices.push_back(elem);
	return elem;
}

int Graph::numVertices(){
	return vertices.size();
}
