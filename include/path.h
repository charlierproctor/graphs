#include "graph.h"

#ifndef PATH_H
#define PATH_H

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

