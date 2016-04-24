#include "graph.h"

graph::graph()
{
}


void graph::addTown(string name, bool capital)
{
  town theTown(name, capital);
  _townVector.insert(_townVector.begin(), theTown);

}

void graph::addRoad(string currentTown, string nextTown, int ditance, bool bridge)
{
  road theRoad(currentTown, nextTown, ditance, bridge);
  _roadVector.insert(_roadVector.begin(), theRoad);
}

void graph::printRoads()
{
  vector <road>::iterator it;
  for (it = _roadVector.begin(); it != _roadVector.end(); it++)
  {
    cout << it->getCurrentTown() << endl;
  }
}

// May add this at some point
// void graph::iterate()
// {}
