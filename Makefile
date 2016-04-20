project5: road.o town.o graph.o project5.o
	g++ -o $@ $^
graph.o: graph.h
road.o: road.h
town.o: town.h

$.0: $.cc
	g++ -c $<
