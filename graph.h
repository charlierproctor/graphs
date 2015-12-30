#include <vector>
#include "node.h"

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
	/**
	 * @brief construct a Graph object
	 */
	Graph ();
	
	/**
	 * @brief destroy a Graph object
	 */
	~Graph ();
	
	/**
	 * @brief the vertices of this graph
	 */
	std::vector<Node *> vertices;
	
	/**
	 * @brief create a new vertex
	 *
	 * @param label number to labell this node with
	 *
	 * @return the created node
	 */
	Node *createVertex(int label = -1);
	
	/**
	 * @brief calculate the number of vertices
	 *
	 * @return number of vertices in this graph
	 */
	int numVertices();
private:
};

#endif

