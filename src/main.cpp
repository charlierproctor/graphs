#include "graph.h"
#include "complete.h"
#include "cycle.h"
#include "path.h"
#include "search.h"

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
	bool search = false;

	// parse the command-line arguments
	int c;
	while (!search && (c = getopt(argc, argv, "g:n:t:dS")) != -1) {
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
			case 'd':	// print dot representation
				dot = true;
				break;
			case 'S':
				search = true;
				break;
			case '?':	// error parsing arg
				exit(EXIT_FAILURE);
				break;
		} 	
	}

	Graph *g;

	// create and draw a COMPLETE GRAPH
	if (graph == "complete") {
		g = new CompleteGraph(num, graph, type);
		
		cerr << "CompleteGraph: ";		

	// create and draw a CYCLE GRAPH
	} else if (graph == "cycle") {
		g = new CycleGraph(num, graph, type);
		
		cerr << "CycleGraph: ";
		
	// create and draw a PATH GRAPH
	} else if (graph == "path") {
		g = new PathGraph(num, graph, type);
		
		cerr << "PathGraph: ";
		
	// invalid graph type
	} else {
		cerr << graph << ": invalid graph type" << endl;
		exit(EXIT_FAILURE);
	}

	cerr << " numVertices " << g->numVertices() << ", numEdges " << g->numEdges() << endl;


	// print the graph, as appropriate
	if (dot) {
		g->dot();
	}

	int from = 0, to = 0;
	search_t st = BFS;

	// parse the search arguments
	while (search && (c = getopt(argc, argv, "f:t:bd")) != -1) {
		switch (c) {
			case 'f':	// from this vertex
				from = atoi(optarg);
				break;
			case 't':	// to this vertex
				to = atoi(optarg);
				break;
			case 'b':	// breadth-first
				st = BFS;
				break;
			case 'd':	// depth-first
				st = DFS;
				break;
			case '?':	// error parsing arg
				exit(EXIT_FAILURE);
				break;
		} 	
	}

	// and perform the search
	if (search) {
		if (st == BFS) {
			cerr << "found: " << bfs(g->vertices[from],g->vertices[to])->label << " from: " << from << endl;
		} else {
			cerr << "found: " << dfs(g->vertices[from],g->vertices[to]) << " from: " << from << endl;
		}
	}

	return 0;
}
