#include <vector>
#include "node.h"

class Graph
{
public:
	Graph ();
	std::vector<Node *> vertices;
	Node *createVertex(int label = -1);
	int numVertices();
private:
};
