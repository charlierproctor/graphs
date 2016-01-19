#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <iostream>
#include <fstream>
#include <regex>
#include <stack>
#include <queue>
#include <algorithm>

#ifndef GRAPH_H
#define GRAPH_H

/**
 * @brief enum type used in graphs / nodes.
 */
enum graph_t { 
	DIRECTED,
	UNDIRECTED
};

class Node
{
public:
	/**
	 * @brief Construct a Node object
	 *
	 * @param label an integer label for this node
	 */
	Node (int label);

	/**
	 * @brief the label for this node; must be unique
	 */
	int label;

	/**
	 * @brief height of the node, used in trees
	 */
	int height;

	/**
	 * @brief depth of the node, used in Graph::hasCycle()
	 */
	int depth;
	
	/**
	 * @brief push an adjacent node
	 *
	 * @param elem the node to push
	 */
	void connect(Node* elem, graph_t type = UNDIRECTED);

	/**
	 * @brief set of the adjacent nodes
	 */
	std::set<Node *> adj_nodes;

	/**
	 * @brief whether we've visited this node, used during search.
	 */
	bool visited;
};

/**
 * @brief an edge connects two nodes.
 */
struct Edge {
	Node *from;	// ending node
	Node *to;	// starting node
	graph_t type; 	// type of the connection
};

// the two types of searches
enum search_t {
	BFS,	// breadth-first search
	DFS	// depth-first search
};

class Graph
{
public:
	
	/**
	 * @brief construct a Graph object from a file (dot representation)
	 *
	 * @param str the stream to read
	 */
	Graph (std::istream &str);

	/**
	 * @brief construct a Graph object
	 */
	Graph (std::string _name = "graph", graph_t _type = UNDIRECTED);
	
	/**
	 * @brief destroy a Graph object
	 */
	~Graph ();
	
	/**
	 * @brief name of the Graph
	 */
	std::string name;

	/**
	 * @brief type of the Graph (UNDIRECTED or DIRECTED)
	 */
	graph_t type;

	/**
	 * @brief a map (label -> ptr) of the vertices of this graph
	 */
	std::map<int,Node *> vertices;

	/**
	 * @brief the edges of this graph
	 */
	std::set<Edge *> edges;

	/**
	 * @brief create a new vertex
	 *
	 * @param label label the vertex
	 *
	 * @return the created node
	 */
	Node *createVertex(int label);
	
	/**
	 * @brief create a new vertex
	 *
	 * @return the created node
	 */
	Node *createVertex();
	
	/**
	 * @brief create a new edge
	 *
	 * @param from the starting vertex
	 * @param to the ending vertex
	 * @param type the type of the connection (UNDIRECTED or DIRECTED)
	 *
	 * @return the new edge we created.
	 */
	Edge *createEdge(Node *from, Node *to, graph_t type = UNDIRECTED);

	/**
	 * @brief print the graph for visualization using `dot`.
	 */
	void dot();

	/**
	 * @brief perform breadth-first search through a graph
	 *
	 * @param start which node to start at
	 * @param find the node we're attempting to find
	 *
	 * @return the node we found 
	 */
	Node *bfs(Node *start, Node *find);

	/**
	 * @brief perform depth-first search through a graph
	 *
	 * @param start which node to start at
	 * @param find the node we're attempting to find
	 *
	 * @return the node we found
	 */
	Node *dfs(Node *start, Node *find);
	
	/**
	* @brief whether or not the graph is connected
	 *
	 * @return boolean; whether the graph is connected
	 */
	bool isConnected();

	/**
	 * @brief whether or not the graph is connected
	 *
	 * @return boolean; whether the graph is connected
	 */
	bool hasCycle();

	/**
	 * @brief is this graph a tree?
	 *
	 * @return boolean: whether the graph is a tree
	 */
	bool isTree();

	/**
	 * @brief is this graph isomophic to g
	 *
	 * @param g the graph to compare against
	 *
	 * @return true (isomorphic) or false.
	 */
	bool isomorphic(Graph *g);

protected:
	/**
	 * @brief reset visited to false on all nodes.
	 */
	void resetVisited();
};

#endif

