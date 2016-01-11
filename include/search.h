#include "graph.h"
#include <queue>
#include <stack>

#ifndef SEARCH_H
#define SEARCH_H


/**
 * @brief perform breadth-first search through a graph
 *
 * @param start which node to start at
 * @param find label on the node we're attempting to find
 *
 * @return the node we found 
 */
Node *bfs(Node *start, int find);

/**
 * @brief perform depth-first search through a graph
 *
 * @param start which node to start at
 * @param find label on the node we're attempting to find
 *
 * @return the node we found
 */
Node *dfs(Node *start, int find);

#endif

