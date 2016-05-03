#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <limits>

#include "town.h"
#include "road.h"


using std::ifstream;
using std::vector;
using std::queue;
using std::list;
using std::cerr;



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
        bool townInVector(vector<town*> townVector, string townName);

        void removeTownFromVector(vector<town> *townVector, string townName);
        void removeRoadFromVector(vector<road> *roadVector, road theRoad);

private:
        vector <road> _roadVector;
        vector <town> _townVector;

};
