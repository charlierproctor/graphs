#include <vector>

class Node
{
public:
	Node (int label = -1);
	int label;
	void pushNode(Node* elem);
	std::vector<Node *> adj_nodes;
private:
};
