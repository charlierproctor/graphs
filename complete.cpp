#include <iostream>
#include "complete.h"

using namespace std;

CompleteGraph::CompleteGraph(int size) {
	
	// create the vertices
	for (int i = 0; i < size; ++i) {
		createVertex(i);
	}

	// connect each vertex to every other vertex
	for (Node *from : vertices) {
		for (Node *to : vertices) {
			if (from != to) {
				from->pushNode(to);
			}
		}
	}

}

CompleteGraph::~CompleteGraph(){

}
