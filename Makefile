CXX = g++
CXXFLAGS = -ggdb3 -std=c++11 -Wall

graph: main.o node.o graph.o complete.o
	     $(CXX) $(CXXFLAGS) -o $@ $^

node.o: node.h
graph.o: node.h graph.h
complete.o: graph.h complete.h
main.o: graph.h complete.h
