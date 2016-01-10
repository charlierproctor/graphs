#include "graph.h"

#ifndef CYCLE_H
#define CYCLE_H

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

#endif

