#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <fstream>
#include <functional>
#include <utility>

#include "town.h"
#include "road.h"


using std::ifstream;
using std::vector;
using std::list;
using std::queue;
using std::stack;
using namespace std;


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

private:
        vector <road> _roadVector;
        vector <town> _townVector;

};
