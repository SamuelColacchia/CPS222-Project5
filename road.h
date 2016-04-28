#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class town;

class road {

public:
        road(town & currentTown, town & nextTown, int distance, bool bridge);

public:
        string getCurrentTown();

        string getNextTown();

private:
        int _distance;
        bool _bridge;
        town &  _currentTown;
        town &  _nextTown;

};
