#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class town {
public:
        town(string name, bool capital);
        getTown(string townName, town theTown);

private:
        string _name;
        bool _capital;

};
