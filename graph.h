#include <vector>
#include <string>
#include <iostream>
#include <set>

#ifndef GRAPH_H
#define GRAPH_H

#include "types.h"
#include "node.h"

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
	 * @brief the vertices of this graph
	 */
	std::vector<Node *> vertices;
	
	/**
	 * @brief create a new vertex
	 *
	 * @return the created node
	 */
	Node *createVertex();
	
	/**
	 * @brief calculate the number of vertices
	 *
	 * @return number of vertices in this graph
	 */
	int numVertices();

	/**
	 * @brief calculate the number of edges
	 *
	 * @return number of edges in this graph
	 */
	int numEdges();

	/**
	 * @brief print the graph for visualization using `dot`.
	 */
	void dot();
private:
};

#endif

