#include <string>
#include <iostream>
#include <set>
#include <map>
#include <iterator>
#include <stack>

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
	 * @brief Destroy a Node object
	 */
	~Node ();

	/**
	 * @brief the label for this node; must be unique
	 */
	int label;

	/**
	 * @brief height of the node, used in trees
	 */
	int height;
	
	/**
	 * @brief depth of the node, used in trees
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
private:
};

/**
 * @brief an edge connects two nodes.
 */
struct Edge {
	Node *from;	// ending node
	Node *to;	// starting node
	graph_t type; 	// type of the connection
};


class Graph
{
public:
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
	 * @brief height of a tree
	 */
	int height;

	/**
	 * @brief root of the tree
	 */
	Node *root;
private:
};

#endif

