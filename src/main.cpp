#include "graph.h"
#include "graph_types.h"
#include "search.h"

#include "string.h"
#include "unistd.h"

using namespace std;

int main(int argc, char *argv[])
{
	// default arguments
	int num = 5, m = 5, children = 2; 
	string graph = "complete"; 
	graph_t type = UNDIRECTED;
	bool dot = false;
	bool search = false;

	// parse the command-line arguments
	int c;
	while (!search && (c = getopt(argc, argv, "g:n:m:t:c:dS")) != -1) {
		switch (c) {
			case 'g':	// graph name
				graph = string(optarg);
				break;
			case 'n':	// size of the graph
				num = atoi(optarg);
				break;
			case 'm':
				m = atoi(optarg);
				break;
			case 't':	// graph type (directed, undirected)
				type = (!strcmp(optarg,"directed") ? DIRECTED : UNDIRECTED);
				break;
			case 'd':	// print dot representation
				dot = true;
				break;
			case 'c':	// how many of the tree
				children = atoi(optarg);
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

	// create a COMPLETE GRAPH
	if (graph == "complete") {
		g = new CompleteGraph(num, graph, type);

	// create a COMPLETE BIPARTITE GRAPH
	} else if (graph == "bipartite") {
		g = new CompleteBipartiteGraph(num, m, graph, type);

	// create a CYCLE GRAPH
	} else if (graph == "cycle") {
		g = new CycleGraph(num, graph, type);
		
	// create a PATH GRAPH
	} else if (graph == "path") {
		g = new PathGraph(num, graph, type);

	} else if (graph == "tree") {
		g = new FullCompleteTree(graph, children, num);

	// invalid graph type
	} else {
		cerr << graph << ": invalid graph type" << endl;
		exit(EXIT_FAILURE);
	}

	cerr << "numVertices: " << g->vertices.size() << ", numEdges: " << g->edges.size() << endl;


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

	// process search option
	if (search) {
		// perform the search
		Node *res;
		if (st == BFS) {
			res = bfs(g->vertices[from],g->vertices[to]);
		} else {
			res = dfs(g->vertices[from],g->vertices[to]);
		}

		// print out the results of the search
		if (res) {
			cerr << "found: " << res->label << " from: " << from << endl;
		} else {
			cerr << "not found" << endl;
		}
	}

	return 0;
}
