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
    //then print out all the towns connected to it
    for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
    {
      if (currentCity == roadIt->getTownOne())
      {
        cout << "\t" << roadIt->getTownTwo() << " " << roadIt->getDistance() << endl;
      }
      else if (currentCity == roadIt->getTownTwo())
      {
        cout << "\t" << roadIt->getTownOne() << " " << roadIt->getDistance() << endl;
      }
    }

    //go through all the roads
    for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
    {
      //get the names of town one
      string townOne = roadIt->getTownOne();
      string townTwo= roadIt->getTownTwo();

      int i = 0;
      bool search;


      if (townOne == currentCity)
      {
        search = false;
        //find the town in the array of towns
        while (search == false)
        {
          if (townTwo == _townVector[i].getTownName())
          {
            search = true;
          }
          else
          {
            i++;
          }
        }
      }
      else if (townTwo == currentCity)
      {
        search = false;
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


/**
 * function to calculate the roads to upgrade to connect all nodes on the graph
 *
 * @description : Works through the graph finding the shortest distance to connect all elements on the graph
 * via the shortest route possible. This function is made in such a way that it should hit
 * the shortest route not matter if it invovles back tracking and weird loop. To accomplish this it works
 * in a number of steps.
 *
 * @step1 : get to the smallest road
 * @step1 - description : This step could be considered unnesary since to peform this algorithm you just
 * need to pick any point
 *
 * @step2 : Keep going while our visitedTowns vector size is smaller then the _townVector size
 * @step2.1 : Loop through all our visitedTowns, this is done to ensure we only add roads that connect to
 * our known towns
 * @step2.2 : Then ask our towns for all the roads that connect to it
 * @step2.3 : Looking for a road that adds a unknown town to our known towns vector
 * @step2.4 : Each time looking for the smallest road
 *
 */
void graph::roadUpgrade()
{
  vector<road>::iterator roadIt;

  vector<road *>::iterator roadPIt;
  vector<town *>::iterator townIt;

  vector<road> finalVector;
  vector<town *> visitedTowns;

  int currentSmallestRoadNum;

  road currentSmallestRoad = *_roadVector.begin();

  //@step1
  for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
  {
    if (currentSmallestRoad.getDistance() > roadIt->getDistance())
    {
      currentSmallestRoad = *roadIt;
    }
  }

  if (_debug)
  {
    cout << currentSmallestRoad.getDistance() << endl;
  }

  /**
   * After completing step 1 add the first/starting road to are final vector
   */
  finalVector.push_back(currentSmallestRoad);
  visitedTowns.push_back(currentSmallestRoad.getTownOnePointer());
  visitedTowns.push_back(currentSmallestRoad.getTownTwoPointer());

  //@step2
  while (visitedTowns.size() < _townVector.size())
  {
    //Reset the smallest road num to a extremely large number
    currentSmallestRoadNum = std::numeric_limits<int>::max();

    //@step2.1
    for (townIt = visitedTowns.begin(); townIt != visitedTowns.end(); townIt++)
    {
      if (_debug)
      {
        cout << endl;
        cout << "current Town working:" << (*townIt)->getTownName() << endl;
      }

      //@step2.2
      for (int roadPos = 0; roadPos < (*townIt)->getConRoadVector().size(); roadPos++)
      {
        if (_debug)
        {
          cout << "\t canidate Towns" << endl;
          cout << "\t \t one:" << (*townIt)->getConRoadVector()[roadPos]->getTownOne() << endl;
          cout << "\t \t two:" << (*townIt)->getConRoadVector()[roadPos]->getTownTwo() << endl;
        }
        //@step2.3
        if (!townInVector(visitedTowns, (*townIt)->getConRoadVector()[roadPos]->getTownOne()) ||
            !townInVector(visitedTowns, (*townIt)->getConRoadVector()[roadPos]->getTownTwo()))
        {
          //@step2.4
          if ((*townIt)->getConRoadVector()[roadPos]->getDistance() < currentSmallestRoadNum)
          {
            if (_debug)
            {
              cout << " \t Town Picked:" << endl;
              cout << "\t \t one:" << (*townIt)->getConRoadVector()[roadPos]->getTownOne() << endl;
              cout << "\t \t two:" << (*townIt)->getConRoadVector()[roadPos]->getTownTwo() << endl;
            }
            currentSmallestRoad = (*(*townIt)->getConRoadVector()[roadPos]);
            currentSmallestRoadNum = currentSmallestRoad.getDistance();
          }
        }
      }
    }
    if (_debug)
    {
      cout << "one:" << currentSmallestRoad.getTownOne() << "->" << "two:" << currentSmallestRoad.getTownTwo() << "||" << currentSmallestRoad.getDistance() << endl;
      cout << endl;
      cout << endl;
    }

    /**
     * Add the current smallest Road to the final vector
     */
    finalVector.push_back(currentSmallestRoad);

    /**
     * Check to see if the road on each side is in our vistedTowns if not add it else do nothing.
     * We do not want to add duplicates to this vector since we use to to see if we are done.
     */
    if (!townInVector(visitedTowns, currentSmallestRoad.getTownOne()))
    {
      visitedTowns.push_back(currentSmallestRoad.getTownOnePointer());
    }

    if (!townInVector(visitedTowns, currentSmallestRoad.getTownTwo()))
    {
      visitedTowns.push_back(currentSmallestRoad.getTownTwoPointer());
    }
  }

  cout << "shortest path:" << endl;

  /**
   * Simple loop, working through i final vector and printing out the roads we used to connect the graph
   */
  for (roadIt = finalVector.begin(); roadIt != finalVector.end(); roadIt++)
  {
    cout << roadIt->getTownOne() << "<->" << roadIt->getTownTwo() << ": " << roadIt->getDistance() << endl;
  }
}




//jordon helped me(matt) with this, and stack overflow :)
int graph::smallestPath(int D[], list<int> toVisit)
{
  int smallestPath = toVisit.front();

  if (toVisit.size() > 1)
  {
    for (int i = 0; i < _townVector.size(); i++)
    {
      if (D[smallestPath] > D[i])
      {
        //found this on stack overflow
        bool found = (std::find(toVisit.begin(), toVisit.end(), i)
                      != toVisit.end());
        if (found)
        {
          smallestPath = i;
        }
      }
    }
  }
  return smallestPath;
}


void graph::dijkstraMethod()
{
  int prev[_townVector.size()];

  vector<road>::iterator roadIt;
  list<int> toVisit;
  string townOne;
  string townTwo;
  bool search;
  int D[_townVector.size()];

  for (int i = 0; i < _townVector.size(); i++)
  {
    D[i] = 100000000;
    toVisit.push_back(i);
  }

  D[0] = 0;


  while (!toVisit.empty())
  {
    int smallestDistance = smallestPath(D, toVisit);
    toVisit.remove(smallestDistance);

    if (_debug)
    {
      std::cout << toVisit.size() << std::endl;
    }
    for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
    {
      townOne = roadIt->getTownOne();
      townTwo = roadIt->getTownTwo();
      int k = 0;

      if (townOne == _townVector[smallestDistance].getTownName())
      {
        search = false;
        //find the town in the array of towns
        while (search == false)
        {
          if (townTwo == _townVector[k].getTownName())
          {
            search = true;
          }
          else
          {
            k++;
          }
        }
      }
      else if (townTwo == _townVector[smallestDistance].getTownName())
      {
        search = false;
        //find the town in the array of towns
        while (search == false)
        {
          if (townOne == _townVector[k].getTownName())
          {
            search = true;
          }
          else
          {
            k++;
          }
        }
      }


      int newD = D[smallestDistance] + roadIt->getDistance();
      if (_debug)
      {
        cout << newD << std::endl;
        cout << D[k] << std::endl;
      }

      if (newD < D[k])
      {
        D[k] = newD;
        prev[k] = smallestDistance;
      }
    }
  }
  for (int i = 1; i < _townVector.size(); i++)
  {
    int nextCity;
    cout << "      " << "The shortest route from " + _townVector[0].getTownName();
    cout << " to " + _townVector[i].getTownName() + " is " << D[i] << " mi:" << endl;
    nextCity = prev[i];
    cout << _townVector[nextCity].getTownName() << endl;
  }
}


/**
 * Function to check if a given town name is in a vector of type town
 *
 * @param vector<town *> townVector : the given vector to check
 * @param string townName : the name of the town we want to check
 *
 * @return bool : True if the townName is in the vector and False if it does not
 *
 * @description : loops through the vector checking each element if that townName is
 * is the name we are looking for.
 *
 */
bool graph::townInVector(vector<town *> townVector, string townName)
{
  vector<town *>::iterator townIt;

  for (townIt = townVector.begin(); townIt != townVector.end(); townIt++)
  {
    if ((*townIt)->getTownName() == townName)
    {
      return true;
    }
  }
  return false;
}



//NOTE: Not current used

/**
 * Attempts to remove a town from a given vector
 *
 * @param vector<town> *townVector : the given vector we want to remove from
 * @param string townName : the name of the town we want to remove
 *
 * @description : Loops through the vector and check to see if the given townName is in the vector
 * if so then we erase the item
 */
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


//NOTE: Not current used

/**
 * Attempts to remove a road from a given vector
 *
 * @param vector<road> *roadVector : the given vector we want to remove from
 * @param string theRoad : the name of the road we want to remove
 *
 * @description : Attempts to remove a road from a vector if both of its towns
 * match the towns of the input road
 */
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
