#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class road {

public:
        road();

private:
        static int const _distance;
        bool _bridge;
        string static const _currentTown;
        string static const _nextTown;

};
