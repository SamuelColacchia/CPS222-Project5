#include "road.h"


road::road(string townOneString, string townTwoString, int distance, bool bridge)
  : _townOneString(townOneString), _townTwoString(townTwoString), _distance(distance), _bridge(bridge)
{
}

// road::~road()
// {}


/**
* Get the Town one name
*
* @description : public function to get the name of the town connected on one side of this road.
*/
string road::getTownOne()
{
  return _townOneString;
}

/**
* Get the Town two name
*
* @description : public function to get the name of the town connected on one side of this road.
*/
string road::getTownTwo()
{
  return _townTwoString;
}


/**
* Get the road length
*
* @description : public function to get the length of this road object.
*/
int road::getDistance()
{
  return _distance;
}

/**
* Check if this road is a bridge
*
* @description : public function to check if this road is a bridge.
*/
bool road::checkBridge(){
  return _bridge;
}

/**
* Set town one pointer
*
* @param town* theTown : pointer to a town
*
* @description : public function to set the town pointer in this road object to the town it is connected to.
*/
void road::setTownOnePointer(town* theTown)
{
  _townOne = theTown;
}

/**
* Set town two pointer
*
* @param town* theTown : pointer to a town
*
* @description : public function to set the town pointer in this road object to the town it is connected to.
*/
void road::setTownTwoPointer(town* theTown)
{
  _townTwo = theTown;
}
