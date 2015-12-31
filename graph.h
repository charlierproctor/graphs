#include <vector>
#include <string>
#include "node.h"

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
	/**
	 * @brief construct a Graph object
	 */
	Graph (std::string _name = "graph");
	
	/**
	 * @brief destroy a Graph object
	 */
	~Graph ();
	
	/**
	 * @brief name of the Graph
	 */
	std::string name;

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

