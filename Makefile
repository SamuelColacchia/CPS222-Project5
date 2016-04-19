project5: edge.o vertice.o project5.o
	g++ -o $@ $^
edge.o: edge.h
vertice.o: vertice.h

$.0: $.cc
	g++ -c $<
