#include <fstream>
#include <vector>

#include "town.h"
#include "road.h"


using std::ifstream;
using std::vector;


class graph
{
public:
        graph();

        void addTown(string name, bool capital);
        void addRoad(town & currentTown, town & nextTown, int ditance, bool bridge);
        void printRoads();

private:
        vector <road> _roadVector;
        vector <town> _townVector;

};
