project5:  Graph.o project5.o
	g++ -o $@ $^
graph.o: Graph.h

$.0: $.cc
	g++ -c $<
