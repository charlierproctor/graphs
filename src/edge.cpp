#include "graph.h"

using namespace std;

bool Edge::operator== (const Edge& e) {
	// must be the same type
	return ((this->type == e.type) 
		
		// directed / undirected case
		&& (((this->from->label == e.from->label)
			&& (this->to->label == e.to->label))

			// reverse undirected case
			|| ((this->type == UNDIRECTED) && (this->to->label == e.from->label)
				&& (this->from->label == e.to->label))));
}

bool Edge::operator!= (const Edge& e) {
	return !this->operator==(e);
}

bool Edge::operator< (const Edge& e) {
	return (this->from->label < e.from->label);
}
bool Edge::operator<= (const Edge& e) {
	return (this->from->label <= e.from->label);
}
bool Edge::operator> (const Edge& e) {
	return (this->from->label > e.from->label);
}
bool Edge::operator>= (const Edge& e) {
	return (this->from->label >= e.from->label);
}
