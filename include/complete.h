#include "graph.h"

#ifndef COMPLETE_H
#define COMPLETE_H

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

#endif

