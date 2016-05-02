#include <fstream>
#include <vector>
#include <queue>

#include "town.h"
#include "road.h"


using std::ifstream;
using std::vector;
using std::queue;



class graph
{
public:
        graph();

        void addTown(string name, bool capital);
        void addRoad(string townOneString, string townTwoString, int distance, bool bridge);
        void printTest();

        void connectRoadsTowns();
        void bfs();

        void roadUpgrade();

private:
        vector <road> _roadVector;
        vector <town> _townVector;

};
