#include "graph.h"

graph::graph()
{
}

/**
* Add a town to this graph
*
* @param string name : the name of the town
* @param bool capitial : boolean to declare if this town is the capital for this graph
*
* @description : Given the inputed parameters create a town object then addes the object to
* the town vector containter.
*/
void graph::addTown(string name, bool capital)
{
  town theTown(name, capital);

  _townVector.push_back(theTown);
}

/**
* Add a road to this graph
*
* @param string townOneString : name of the town on one side of the road
* @param string townTwoString : name of the town on the other side of the road
* @param int distance : the length of the road
* @param bool brigde : boolean to declare if this road is a bridge
*
* @description : Given the inputed paramters creates a road object then addes the object to
* the road vector container.
*/
void graph::addRoad(string townOneString, string townTwoString, int distance, bool bridge)
{
  road theRoad(townOneString, townTwoString, distance, bridge);

  _roadVector.push_back(theRoad);
}

/**
* Function to connect roads and towns
*
* @description : Works through the roadVector and then works to link roads and towns
* using pointers. Sets the town one and two pointers in the road to point to the town
* object on both sides of the road. Adds a pointer to all the roads to a vector in the town object.
*/
void graph::connectRoadsTowns()
{
  string TownOne;
  string TownTwo;

  string currentTown;

  vector<road>::iterator roadIt;
  vector<town>::iterator townIt;
  for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
  {
    TownOne = roadIt->getTownOne();
    TownTwo = roadIt->getTownTwo();

    for (townIt = _townVector.begin(); townIt != _townVector.end(); townIt++)
    {
      currentTown = townIt->getTownName();

      if (currentTown == TownOne)
      {
        roadIt->setTownOnePointer(&*townIt);
        townIt->addRoadPointer(&*roadIt);
      }
      else if (currentTown == TownTwo)
      {
        roadIt->setTownTwoPointer(&*townIt);
        townIt->addRoadPointer(&*roadIt);
      }
    }
  }
}


void graph::printTest()
{
  vector<town>::iterator it;
  for (it = _townVector.begin(); it != _townVector.end(); it++)
  {
    cout << it->getTownName() << endl;
  }
}


void graph::bfs()
{
  //createa vector iterator for the roads
  //and a bool array, then set the entire array to false
  vector<road>::iterator roadIt;
  bool scheduled [_townVector.size()];
  for (int i = 0; i < _townVector.size(); i++)
  {
    scheduled[i] = false;
  }
  //create a queueand push the first number interation and set the first city
  // in schedruled to true
  queue<int> toVisit;
  toVisit.push(0);
  scheduled[0] = true;

  while (!toVisit.empty())
  {
    //get the number to the first town in the queue
    int current = toVisit.front();
    toVisit.pop();
    //get the name of that city using the city array
    string currentCity = _townVector[current].getTownName();
    //print the city name
    cout << currentCity << endl;
    int k = 0;
    //then print out all the towns connected to it
    for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
    {
      if (currentCity == roadIt->getTownOne())
      {
        cout << "\t" << roadIt->getTownTwo() << " " << roadIt->getDistance() << endl;
      }
    }

    //go through all the roads
    for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
    {
      //get the names of town one
      string townOne = roadIt->getTownOne();
      int i = 0;
      bool search = false;
      //find the town in the array of towns
      while (search == false)
      {
        if (townOne == _townVector[i].getTownName())
        {
          search = true;
        }
        else
        {
          i++;
        }
      }
      //sif first time visited set the position of that city to true in
      //the visited array and push it to toVisist
      if (!scheduled[i])
      {
        toVisit.push(i);
        scheduled[i] = true;
      }
    }
  }
}

void graph::roadUpgrade()
{
  
}


// void graph::Kruskal(){
//
// }


// May add this at some point
// void graph::iterate()
// {}
