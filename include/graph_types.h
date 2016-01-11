#include "graph.h"

#ifndef GRAPH_TYPES_H
#define GRAPH_TYPES_H

class CompleteGraph: public Graph
{
public:
	/**
	 * @brief construct a CompleteGraph
	 * 
	 * @param size number of vertices
	 */
	CompleteGraph (int size, std::string _name = "complete", graph_t _type = UNDIRECTED);
	
	/**
	 * @brief destroy a CompleteGraph
	 */
	~CompleteGraph ();
	
private:
};

class CompleteBipartiteGraph: public Graph
{
public:
	/**
	 * @brief construct a CompleteBipartiteGraph
	 * 
	 * @param size number of vertices
	 */
	CompleteBipartiteGraph (int n, int m, std::string _name = "bipartite", graph_t _type = UNDIRECTED);
	
	/**
	 * @brief destroy a CompleteBipartiteGraph
	 */
	~CompleteBipartiteGraph ();
};

class CycleGraph: public Graph
{
public:
	/**
	 * @brief construct a CycleGraph
	 * 
	 * @param size number of vertices
	 */
	CycleGraph (int size, std::string _name = "cycle", graph_t _type = UNDIRECTED);
	
	/**
	 * @brief destroy a CycleGraph
	 */
	~CycleGraph ();
	
private:
};

class PathGraph: public Graph
{
public:
	/**
	 * @brief construct a PathGraph
	 * 
	 * @param size number of vertices
	 */
	PathGraph (int size, std::string _name = "path", graph_t _type = UNDIRECTED);
	
	/**
	 * @brief destroy a PathGraph
	 */
	~PathGraph ();
	
private:
};

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

