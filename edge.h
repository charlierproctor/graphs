
#ifndef EDGE_H
#define EDGE_H

#include "types.h"
#include "node.h"

/**
 * @brief an edge connects two nodes.
 */
struct Edge {
	Node *from;	// ending node
	Node *to;	// starting node
	graph_t type; 	// type of the connection
};

#endif

