#include "graph.h"
#include "graphs.h"
#include "trees.h"

#include "string.h"
#include "unistd.h"

using namespace std;

int main(int argc, char *argv[])
{
	// default arguments
	int num = 5, m = 5, children = 2; 
	string graph = "complete"; 
	graph_t type = UNDIRECTED;
	string property;
	bool dot = false, search = false, read = false;

	// parse the command-line arguments
	int c;
	while (!search && (c = getopt(argc, argv, "g:r:n:m:t:c:p:dS")) != -1) {
		switch (c) {
			case 'g':	// graph name
				graph = string(optarg);
				break;
			case 'r':	// read graph from stdin / file
				read = true;
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
			case 'p':
				property = string(optarg);
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

	// create the graph from a file
	if (read) {
		ifstream file;

		if (graph == "+") {
			g = new Graph(cin);
		} else if (file.open(graph, ios::in), file.is_open()) {
			g = new Graph(file);
		} else {
			cerr << "Unable to open " << graph << endl;
			exit (EXIT_FAILURE);
		}

	// create a COMPLETE GRAPH
	} else if (graph == "complete") {
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

	// create a TREE
	} else if (graph == "tree") {
		g = new FullCompleteTree(graph, children, num);

	// invalid graph type
	} else {
		cerr << graph << ": invalid graph type" << endl;
		exit(EXIT_FAILURE);
	}

	cerr << "numVertices: " << g->vertices.size() << ", numEdges: " << g->edges.size() << endl;

	if (!property.empty()){
		cerr << property << ": ";
		if (property == "connected") {
			cerr << boolalpha << g->isConnected() << endl;
		} else {
			cerr << "invalid" << endl;
		}
	}

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
			res = g->bfs(g->vertices[from],g->vertices[to]);
		} else {
			res = g->dfs(g->vertices[from],g->vertices[to]);
		}

		// print out the results of the search
		if (res) {
			cerr << "found: " << res->label << " from: " << from << endl;
		} else {
			cerr << "not found" << endl;
		}
	}

	delete g;

	return 0;
}
