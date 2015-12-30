#include <iostream>
#include "graph.h"
#include "complete.h"

using namespace std;

int main(int argc, char *argv[])
{
	Graph *g = new Graph();
	Node *a = g->createVertex();
	Node *b = g->createVertex();

	a->pushNode(b);
	b->pushNode(a);

	CompleteGraph *cg = new CompleteGraph(5);
		
	return 0;
}
