#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class road;


/*
*
*/
class town {
public:
        town(string name, bool capital);
        // town getTown();

        string getTownName();

        void addRoadPointer(road * theRoad);
        bool checkCapital();

        vector<road*> getConRoadVector();



private:
        string _name;
        bool _capital;
        vector <road*> _conRoadVector;

};
