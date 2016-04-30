#include "road.h"


road::road(string townOneString, string townTwoString, int distance, bool bridge)
  : _townOneString(townOneString), _townTwoString(townTwoString), _distance(distance), _bridge(bridge)
{
}


string road::getTownOne()
{
  return _townOneString;
}

int road::getDistance()
{
  return _distance;
}

bool road::checkBridge(){
  return _bridge;
}

string road::getTownTwo()
{
  return _townTwoString;
}


void road::setTownOnePointer(town* theTown)
{
  _townOne = theTown;
}


void road::setTownTwoPointer(town* theTown)
{
  _townTwo = theTown;
}
