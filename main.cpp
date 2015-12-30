#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char *argv[])
{
	Graph *g = new Graph();
	Node *a = g->createVertex();
	Node *b = g->createVertex();

	a->pushNode(b);
	b->pushNode(a);
	
	return 0;
}
