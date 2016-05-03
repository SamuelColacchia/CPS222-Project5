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
  vector<road>::iterator roadIt;

  vector<road> roadVectorCopy;
  vector<town> townVectorCopy;

  townVectorCopy = _townVector;
  roadVectorCopy = _roadVector;

  vector<road> finalVector;


  road currentSmallestRoad = *(roadVectorCopy.begin());

//   while (townVectorCopy.size() != 0)
//   {
//     // cout << "town vector copy size" << townVectorCopy.size() << endl;
//     for (roadIt = roadVectorCopy.begin(); roadIt != roadVectorCopy.end(); roadIt++)
//     {
//       if (currentSmallestRoad.getDistance() > roadIt->getDistance())
//       {
//         // cout << "townVectorSize:" << townVectorCopy.size() << endl;
//         currentSmallestRoad = *roadIt;
//
//         if (townInVector(townVectorCopy, currentSmallestRoad.getTownTwo()))
//         {
//           cout << "Smallest road" << currentSmallestRoad.getDistance() << endl;
//           continue;
//         }
//         else if (townInVector(townVectorCopy, currentSmallestRoad.getTownTwo()))
//         {
//           cout << "Smallest road" << currentSmallestRoad.getDistance() << endl;
//           continue;
//         }
//         // else
//         // {
//         //   cout << "road removed early" << endl;
//         //   removeRoadFromVector(&roadVectorCopy, currentSmallestRoad);
//         //   currentSmallestRoad = *(roadVectorCopy.begin());
//         // }
//       }
//       cout << "Smallest road" << currentSmallestRoad.getDistance() << endl;
//     }
//     // cout << endl;
//     // cout << endl;
//     // cout << "town 1 remove:" << currentSmallestRoad.getTownOne() << endl;
//     // cout << "town 2 remove:" << currentSmallestRoad.getTownTwo() << endl;
//     // cout << endl;
//     // cout << "loop 1" << endl;
//     if (townInVector(townVectorCopy, currentSmallestRoad.getTownOne()))
//     {
//       // cout << "loop 1 - in" << endl;
//       // cout << townVectorCopy.size() << endl;
//
//
//       removeTownFromVector(&townVectorCopy, currentSmallestRoad.getTownOne());
//     }
//
//     // cout << endl;
//     // cout << "loop 2" << endl;
//
//     if (townInVector(townVectorCopy, currentSmallestRoad.getTownTwo()))
//     {
//       // cout << "loop 2 - in" << endl;
//       // cout << townVectorCopy.size() << endl;
//
//
//       removeTownFromVector(&townVectorCopy, currentSmallestRoad.getTownTwo());
//     }
//     finalVector.push_back(currentSmallestRoad);
//     removeRoadFromVector(&roadVectorCopy, currentSmallestRoad);
//     cout << "road removed" << endl;
//     currentSmallestRoad = *(roadVectorCopy.begin());
//   }
//
//   cout << "shortest path:" << endl;
//   for (roadIt = finalVector.begin(); roadIt != finalVector.end(); roadIt++)
//   {
//     cout << roadIt->getTownOne() << "->" << roadIt->getTownTwo() << ": " << roadIt->getDistance() << endl;
//   }
}


bool graph::townInVector(vector<town> townVector, string townName)
{
  vector<town>::iterator townIt;

  for (townIt = townVector.begin(); townIt != townVector.end(); townIt++)
  {
    if (townIt->getTownName() == townName)
    {
      return true;
    }
  }
  return false;
}


void graph::removeTownFromVector(vector<town> *townVector, string townName)
{
  vector<town>::iterator townIt;

  // cout << "town in delete size:" << townVector->size() << endl;

  for (townIt = townVector->begin(); townIt != townVector->end(); townIt++)
  {
    // cout << "town from it:" << townIt->getTownName() << endl;
    // cout << "the town to remove:" << townName << endl;

    if (townIt->getTownName() == townName)
    {
      townVector->erase(townIt);
      break;
    }
  }
}


void graph::removeRoadFromVector(vector<road> *roadVector, road theRoad)
{
  vector<road>::iterator roadIt;

  for (roadIt = roadVector->begin(); roadIt != roadVector->end(); roadIt++)
  {
    //
    // cout << endl;
    // cout << "road it 1:" << roadIt->getTownOne() << endl;
    // cout << "current road 1:" << theRoad.getTownOne() << endl;
    // cout << endl;
    // cout << "road it 2:" << roadIt->getTownTwo() << endl;
    // cout << "current road 2:" << theRoad.getTownTwo() << endl;

    if ((roadIt->getTownOne() == theRoad.getTownOne()) && (roadIt->getTownTwo() == theRoad.getTownTwo()))
    {
      roadVector->erase(roadIt);
      break;
    }
  }
}


// void graph::Kruskal(){
//
// }


// May add this at some point
// void graph::iterate()
// {}
