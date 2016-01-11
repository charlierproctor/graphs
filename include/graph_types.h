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

#endif

