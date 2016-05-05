#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <fstream>
#include <functional>
#include <utility>
#include <algorithm>
#include <limits>

#include "town.h"
#include "road.h"


using std::ifstream;
using std::vector;
using std::list;
using std::queue;
using std::list;
using std::cerr;
using std::stack;


class graph
{
public:
        graph();

        void addTown(string name, bool capital);
        void addRoad(string townOneString, string townTwoString, int distance, bool bridge);
        void printTest();

        void connectRoadsTowns();
        void bfs();
        void dijkstraMethod();
        int smallestPath(int D[], list <int> toVisits);

        void roadUpgrade();
        bool townInVector(vector<town*> townVector, string townName);

        void removeTownFromVector(vector<town> *townVector, string townName);
        void removeRoadFromVector(vector<road> *roadVector, road theRoad);

        void bridgesGone();
        void townDestroyed();

private:
        vector <road> _roadVector;
        vector <town> _townVector;
        static const bool _debug = false;

};
