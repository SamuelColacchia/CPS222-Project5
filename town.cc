#include "town.h"

town::town(string name, bool capital)
:_name(name), _capital(capital)
{}

bool town::getTown(string townName, town theTown)
{

}

/**
* Get the town name
*
* @description : public function to get the name of this town object
*/
string town::getTownName()
{
  return _name;
}


/**
* Check if capital
*
* @descrription : public function to check if this town object is the capital
*/
bool town::checkCapital(){
  return _capital;
}

/**
* Add a road pointer
*
* @param road* theRoad : pointer, pointing to a road that is connected to this town
*
* @description : public function to add road pointer to the connected road vector container. 
*/
void town::addRoadPointer(road * theRoad)
{
  _conRoadVector.push_back(theRoad);
}
