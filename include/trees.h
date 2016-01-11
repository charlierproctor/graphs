#include "graph.h"

#ifndef TREES_H
#define TREES_H

class Tree: public Graph
{
public:
	/**
	 * @brief construct a Tree
	 *
	 * @param _name name to give the tree
	 */
	Tree(std::string _name = "tree");

	/**
	 * @brief destory a Tree
	 */
	~Tree();

	/**
	 * @brief height of a tree
	 */
	int height;

	/**
	 * @brief root of the tree
	 */
	Node *root;
};

class FullCompleteTree: public Tree
{
public:
	/**
	 * @brief construct a FullCompleteTree
	 *
	 * @param _name name of the graph
	 * @param children number of children per node
	 * @param height height of the tree
	 */
	FullCompleteTree (std::string _name = "tree", int children = 2, int height = 2);
	
	/**
	 * @brief destroy a FullCompleteTree
	 */
	~FullCompleteTree ();
};

#endif

