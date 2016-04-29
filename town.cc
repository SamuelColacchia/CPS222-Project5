#include "town.h"

town::town(string name, bool capital)
:_name(name), _capital(capital)
{}

bool town::getTown(string townName, town theTown)
{

}

string town::getTownName()
{
  return _name;
}

bool town::checkCapital(){
  return _capital;
}
void town::addRoadPointer(road * theRoad)
{
  _conRoadVector.push_back(theRoad);
}
