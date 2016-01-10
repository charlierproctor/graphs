#include "graph.h"
#include "complete.h"
#include "cycle.h"
#include "path.h"

#include "string.h"
#include "unistd.h"

using namespace std;

int main(int argc, char *argv[])
{
	// default arguments
	int num = 5; 
	string graph = "complete"; 
	graph_t type = UNDIRECTED;
	bool dot = false;

	// parse the command-line arguments
	int c;
	while ((c = getopt(argc, argv, "g:n:t:d")) != -1) {
		switch (c) {
			case 'g':	// graph name
				graph = string(optarg);
				break;
			case 'n':	// size of the graph
				num = atoi(optarg);
				break;
			case 't':	// graph type (directed, undirected)
				type = (!strcmp(optarg,"directed") ? DIRECTED : UNDIRECTED);
				break;
			case 'd':
				dot = true;
				break;
			case '?':
				exit(EXIT_FAILURE);
				break;
		} 	
	}

	// create and draw a COMPLETE GRAPH
	if (graph == "complete") {
		CompleteGraph *cg = new CompleteGraph(num, graph, type);
		
		cerr << "CompleteGraph: numVertices " << cg->numVertices() << ", numEdges " << cg->numEdges() << endl;
		
		if (dot) {
			cg->dot();
		}

	// create and draw a CYCLE GRAPH
	} else if (graph == "cycle") {
		CycleGraph *cyg = new CycleGraph(num, graph, type);
		
		cerr << "CycleGraph: numVertices " << cyg->numVertices() << ", numEdges " << cyg->numEdges() << endl;
		
		if (dot) {
			cyg->dot();
		}

	// create and draw a PATH GRAPH
	} else if (graph == "path") {
		PathGraph *pg = new PathGraph(num, graph, type);
		
		cerr << "PathGraph: numVertices " << pg->numVertices() << ", numEdges " << pg->numEdges() << endl;
		
		if (dot) {
			pg->dot();
		}
	}

	return 0;
}
