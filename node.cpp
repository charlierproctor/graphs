#include <vector>
#include "node.h"

using namespace std;

Node::Node(int _label){
	label = _label;
}

void Node::pushNode(Node* elem){
	adj_nodes.push_back(elem);
}
