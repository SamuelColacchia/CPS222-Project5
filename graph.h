#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <functional>
#include <climits>
#include <map>

#include "town.h"
#include "road.h"


using std::ifstream;
using std::vector;
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

private:
        vector <road> _roadVector;
        vector <town> _townVector;

};
