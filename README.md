# Graphs

This repository contains an extensible collection of graphs and graphing algorithms written in C++. 

## Setup

Just run `make` to build the executable. If you want to visualize the graphs, you'll need to have graphviz's `dot` utility installed.

## Usage

The principle executable lives in `bin/graph`. Here are the various options:

- `-g NAME`: create the graph specified by NAME. Currently valid options are:
	- `cycle`: generates a Cycle
	- `path`: generates a Path
	- `complete`: generates a Complete Graph
	- `tree`: generates a full and complete tree
	- `bipartite`: generates a Complete Bipartite Graph
- `-r [+|FILE]`: read a graph in from `stdin` (`+`) or from a file (specified by `FILE`). 
	- Must be in proper graphviz format.
- `-n SIZE`: size of the graph. 
	- For cycles, paths and complete graphs, this is the number of vertices. 
	- For trees, this is the height of the tree.
	- For bipartite graphs, this is the number of vertices in one section. The number of vertices in the other section is given by the `-m SIZE` option.
- `-m SIZE`: see above. Specifies the number of vertices of the second piece of a bipartite graph.
- `-c CHILDREN`: number of children of each node in a tree.
- `-t [directed|undirected]`: the type of the graph (undirected or directed). This argument is ignored for trees.
- `-d`: print a `dot` representation of this graph to `stdout`.
- `-p [connected|cycle|tree]`: calculate and print to `stderr` whether the graph is connected, a cycle, or a tree.
- `-S [breadth|depth]`: perform a search through the graph. MUST specify `from`, `to`. All future non-search arguments are ignored (sorry!).
	- `-f FROM`: starting vertex label in the search
	- `-t TO`: vertex to search for.

