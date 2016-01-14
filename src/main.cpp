#include "graph.h"
#include "graphs.h"
#include "trees.h"

#include "string.h"
#include "unistd.h"

using namespace std;

#define USAGE "USAGE: bin/graph [generate|analyze|search]"

int main(int argc, char *argv[])
{

	// bin/graph generate graph [-n N] [-m M] [-t TYPE] [-c CHILDREN] 
	if (argc >= 3 && !strcmp(argv[1],"generate")) {
		
		// declare the variables
		int n = 5,m = 5,children = 2;
		graph_t type = UNDIRECTED;
		string graph = string(argv[2]);
		
		int c;

		// parse the command line argument
		while ((c = getopt(argc - 2, argv + 2, "n:m:t:c:")) != -1) {
			switch (c) {
				case 'n':		// size of the graph (n)
					n = atoi(optarg);
					break;
				case 'm':		// size of the graph (m)
					m = atoi(optarg);
					break;
				case 't':		// DIRECTED vs. UNDIRECTED
					type = (!strcmp(optarg,"directed") ? DIRECTED : UNDIRECTED);
					break;
				case 'c':		// number of children of each node in a tree
					children = atoi(optarg);
					break;
				case '?':		// invalid argument
					exit(EXIT_FAILURE);
					break;
			}
		}

		Graph *g;

		// create a COMPLETE GRAPH
		if (graph == "complete") {
			g = new CompleteGraph(n, graph, type);

		// create a COMPLETE BIPARTITE GRAPH
		} else if (graph == "bipartite") {
			g = new CompleteBipartiteGraph(n, m, graph, type);

		// create a CYCLE GRAPH
		} else if (graph == "cycle") {
			g = new CycleGraph(n, graph, type);
			
		// create a PATH GRAPH
		} else if (graph == "path") {
			g = new PathGraph(n, graph, type);

		// create a TREE
		} else if (graph == "tree") {
			g = new FullCompleteTree(graph, children, n);

		// invalid graph type
		} else {
			cerr << graph << ": invalid graph type" << endl;
			exit(EXIT_FAILURE);
		}

		// print out and delete the generated graph
		g->dot();
		delete g;

	// bin/graph analyze [-p PROPERTY]*
	} else if (argc >= 2 && !strcmp(argv[1],"analyze")) {
		vector<string> properties;
		Graph *g = new Graph(cin);

		// display the number of vertices, edges.
		cerr << "numVertices: " << g->vertices.size() << ", numEdges: " << g->edges.size() << endl;

		int c;

		// parse the command line arguments
		while ((c = getopt(argc - 1, argv + 1, "p:")) != -1) {
			switch (c) {
				case 'p':
					properties.push_back(string(optarg));
					break;
				case '?':
					exit(EXIT_FAILURE);
					break;
			}
		}

		// evaluate the properties as appropriate
		for (string property : properties) {
			cerr << property << ": ";
			if (property == "connected") {
				cerr << boolalpha << g->isConnected() << endl;
			} else if (property == "cycle") {
				cerr << boolalpha << g->hasCycle() << endl;
			} else if (property == "tree") {
				cerr << boolalpha << g->isTree() << endl;
			} else {
				cerr << "invalid" << endl;
			}
		}

		// print and delete the graph
		g->dot();
		delete g;

	// bin/graph search FROM TO [-t TYPE]
	} else if (argc >= 4 && !strcmp(argv[1],"search")) {
		Graph *g = new Graph(cin);

		// to/from arguments, search type.
		int from = atoi(argv[2]), to = atoi(argv[3]);
		search_t st;

		int c;

		// parse the search arguments
		while ((c = getopt(argc - 3, argv + 3, "t:")) != -1) {
			switch (c) {
				case 't':	// search type
					st = (!strcmp(optarg,"depth") ? DFS : BFS);
					break;
				case '?':	// error parsing arg
					exit(EXIT_FAILURE);
					break;
			}
		}

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

		// print and delete the graph
		g->dot();
		delete g;
	} else {
		cerr << USAGE << endl;
	}

	return 0;
}
