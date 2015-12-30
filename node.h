#include <vector>

#ifndef NODE_H
#define NODE_H

class Node
{
public:
	/**
	 * @brief Construct a Node object
	 *
	 * @param label an integer label for this node
	 */
	Node (int label = -1);
	
	/**
	 * @brief Destroy a Node object
	 */
	~Node ();

	/**
	 * @brief the label for this node
	 */
	int label;
	
	/**
	 * @brief push an adjacent node
	 *
	 * @param elem the node to push
	 */
	void pushNode(Node* elem);

	/**
	 * @brief vector of adjacent nodes
	 */
	std::vector<Node *> adj_nodes;
private:
};

#endif

