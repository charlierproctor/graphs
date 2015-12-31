#include <vector>

#ifndef NODE_H
#define NODE_H

#include "types.h"

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
	 * @brief push an adjacent node
	 *
	 * @param elem the node to push
	 */
	void connect(Node* elem, graph_t type = UNDIRECTED);

	/**
	 * @brief vector of adjacent nodes
	 */
	std::vector<Node *> adj_nodes;
private:
};

#endif

