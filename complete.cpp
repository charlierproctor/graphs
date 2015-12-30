#include <iostream>
#include "complete.h"

using namespace std;

CompleteGraph::CompleteGraph(int size) {
	
	for (int i = 0; i < size; ++i) {
		// create a vertex with the label i
		createVertex(i);
	}

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
