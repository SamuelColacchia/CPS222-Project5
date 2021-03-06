/*
 * project5.cc
 *
 * Main program for cps222 project 5
 * Driver to read in formated town and road data
 * Then display relevant information to the user
 *
 * Copyright (c) 2016 - Matthew Felgate & Samuel Colacchia
 *
 */

#include "graph.h"


/*
 * Declaring variables
 *
 * These variables are primarly used for getting the input data from cin
 *
 */

int numTowns;
int numRoads;
string townInput;
string regionCapital;
string roadT1;
string roadT2;
string roadBridge;
bool roadBridgeBool;
int roadDist;

char cinCheck;

int main(int argc, char *argv[])
{
  while (true)
  {
    cin >> cinCheck;

    if (cin.eof())
    {
      break;
    }
    else
    {
      cin.unget();
    }


    graph theGraph;
    cout << "(#TOWNS #ROADS)" << endl;
    cin >> numTowns;
    cin >> numRoads;

    // cout << "towns:" << numTowns << endl;
    // cout << "roads:" << numRoads << endl;

    for (int loopNumTowns = 0; loopNumTowns < numTowns; loopNumTowns++)
    {
      if (loopNumTowns == 0)
      {
        cin >> regionCapital;
        // cout << "regionCapital:" << regionCapital << endl;
        theGraph.addTown(regionCapital, true);
      }
      else
      {
        cin >> townInput;
        // cout << "towninput:" << townInput << endl;
        theGraph.addTown(townInput, false);
      }
    }

    for (int loopNumRoads = 0; loopNumRoads < numRoads; loopNumRoads++)
    {
      cin >> roadT1 >> roadT2 >> roadBridge >> roadDist;
      // cout << "roadT1:" << roadT1 << " roadT2:" << roadT2 << " roadBridge:" << roadBridge << " roadDist:" << roadDist << endl;

      if ((roadBridge == "b") || (roadBridge == "B"))
      {
        roadBridgeBool = true;
      }
      else
      {
        roadBridgeBool = false;
      }

      // cout << "roadBridgeBool" << roadBridgeBool << endl;
      theGraph.addRoad(roadT1, roadT2, roadDist, roadBridgeBool);
    }
    theGraph.connectRoadsTowns();

    theGraph.bfs();
    cout << endl;
    cout << endl;
    theGraph.dijkstraMethod();
    cout << endl;
    cout << endl;
    theGraph.roadUpgrade();
    cout << endl;
    cout << endl;
    theGraph.bridgesGone();
    cout << endl;
    cout << endl;
    theGraph.townDestroyed();
  }
}
