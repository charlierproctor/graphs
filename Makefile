CXX = g++
CXXFLAGS = -ggdb3 -std=c++11 -pedantic -Wall -Werror

graph: main.o node.o graph.o
	     $(CXX) $(CXXFLAGS) -o $@ $^

node.o: node.h
graph.o: node.h graph.h
main.o: node.h graph.h
