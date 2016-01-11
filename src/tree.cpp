#include "graph_types.h"

using namespace std;

FullCompleteTree::FullCompleteTree(string _name, int children, int height):Graph(_name,DIRECTED) {

	// set the height of the tree
	this->height = height;

	// create the root node of the tree
	this->root = createVertex();
	this->root->height = height;

	// use a stack to create the trees
	stack<Node *> s;
	s.push(this->root);

	Node *parent,*child;

	while (!s.empty()) {

		// grab the top node
		parent = s.top();
		s.pop();

		// create and connect the children
		for (int i = 0; i < children; ++i) {
			child = createVertex();
			child->height = parent->height - 1;
			createEdge(parent,child,DIRECTED);
			
			if (child->height > 0) {
				s.push(child);
			}
		}
	}

}

FullCompleteTree::~FullCompleteTree(){
}
