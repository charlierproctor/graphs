#include <vector>
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
	CompleteGraph (int size);
	
	/**
	 * @brief destroy a CompleteGraph
	 */
	~CompleteGraph ();
	
private:
};

#endif

