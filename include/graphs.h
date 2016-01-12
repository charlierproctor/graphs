#include "graph.h"

#ifndef GRAPHS_H
#define GRAPHS_H

class CompleteGraph: public Graph
{
public:
	/**
	 * @brief construct a CompleteGraph
	 * 
	 * @param size number of vertices
	 */
	CompleteGraph (int size, std::string _name = "complete", graph_t _type = UNDIRECTED);
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
};

#endif

