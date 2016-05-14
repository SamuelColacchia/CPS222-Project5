project5: road.o town.o graph.o project5.o
	g++ -o $@ $^
road.o: road.h
town.o: town.h
graph.o: graph.h

$.0: $.cc
	g++ -c $<
