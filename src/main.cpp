#include "graph.h"
#include "complete.h"
#include "cycle.h"
#include "path.h"

using namespace std;

int main(int argc, char *argv[])
{
	// create and test a GRAPH
	Graph *g = new Graph("first", DIRECTED);
	Node *a = g->createVertex();
	Node *b = g->createVertex();

	g->createEdge(a,b,DIRECTED);

	cout << "Graph: numVertices " << g->numVertices() << ", numEdges " << g->numEdges() << endl;
	g->dot();

	// create and test a COMPLETEGRAPH
	CompleteGraph *cg = new CompleteGraph(5);
	cout << "CompleteGraph: numVertices " << cg->numVertices() << ", numEdges " << cg->numEdges() << endl;
	cg->dot();

	// create and test a CYCLEGRAPH
	CycleGraph *cyg = new CycleGraph(5);
	cout << "CycleGraph: numVertices " << cyg->numVertices() << ", numEdges " << cyg->numEdges() << endl;
	cyg->dot();

	// create and test a PATHGRAPH
	PathGraph *pg = new PathGraph(5);
	cout << "PathGraph: numVertices " << pg->numVertices() << ", numEdges " << pg->numEdges() << endl;
	pg->dot();

	return 0;
}
