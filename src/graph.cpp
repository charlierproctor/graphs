#include "graph.h"

using namespace std;

Graph::Graph(istream &str) {

	// get the first line
	string line;
	getline(str, line);

	// find and calculate the type of this graph
	regex type_r("(\\w+)");
	smatch type_matches;
	regex_search(line, type_matches, type_r);
	type = (type_matches[1] == "graph" ? UNDIRECTED : DIRECTED);

	// regex to parse through the edges
	regex edges_r("\"([0-9]+)\".{4}\"([0-9]+)\"");
	smatch edge_matches;

	// read the rest of the line
	while ((getline(str,line))) {
		// searching for our edges
		regex_search(line, edge_matches, edges_r);

		if (edge_matches.size() > 2) {
			
			// create the edges + vertices
			Node *from = createVertex(stoi(edge_matches[1]));
			Node *to = createVertex(stoi(edge_matches[2]));
			createEdge(from,to,type);
		}
	}
}

Graph::Graph(string _name, graph_t _type){
	name = _name;
	type = _type;
}

Graph::~Graph(){

}

Node *Graph::createVertex(int label){

	// a vertex with this label already exists!
	if (vertices.count(label) != 0) {
		return vertices[label];
	}

	// create a new vertex, with this label
	Node *elem = new Node(label);
	vertices[label] = elem;
	return elem;
}

Node *Graph::createVertex(){
	int label = vertices.size();
	return createVertex(label);
}

Edge *Graph::createEdge(Node *from, Node *to, graph_t type){
	Edge *edge = new Edge();
	
	// set the attributes
	edge->to = to;
	edge->from = from;
	edge->type = type;

	// add this edge to our set
	edges.insert(edge);

	// and connect the two with pointers.
	from->connect(to, type);

	return edge;

}

void Graph::dot(){

	if (type == UNDIRECTED) {
		cout << "graph " << name << " { " << endl;
	} else {
		cout << "digraph " << name << " { " << endl;
	}

	string connector = (type == UNDIRECTED ? "--" : "->");

	// iterate through all the edges
	for (Edge *edge : edges) {
		cout << "\"" << edge->from->label << "\" " << connector << " \"" << edge->to->label << "\";" << endl;
	}

	cout << "}" << endl;
	
}
