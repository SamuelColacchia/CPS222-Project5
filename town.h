#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class road;

class town {
public:
        town(string name, bool capital);
        bool getTown(string townName, town theTown);

        string getTownName();

        void addRoadPointer(road * theRoad);


private:
        string _name;
        bool _capital;
        vector <road*> _conRoadVector;

};
