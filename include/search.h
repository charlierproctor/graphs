#include "graph.h"
#include <queue>
#include <stack>

#ifndef SEARCH_H
#define SEARCH_H

// the two types of searches
enum search_t {
	BFS,	// breadth-first search
	DFS	// depth-first search
};

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

#endif

