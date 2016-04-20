#include <fstream>
#include <vector>

#include "town.h"
#include "road.h"

using std::string;
using std::ifstream;
using std::vector;

class graph {

public:
        graph();

private:
        vector <road> _roadVector;
        vector <town> _townVector;

public:
  bool addTown();
  bool addRoad();
};
