#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class town;

class road {

public:
        road(string townOneString, string townTwoString, int distance, bool bridge);

        string getTownOne();
        string getTownTwo();
        int getDistance();
        bool checkBridge();

        void setTownOnePointer(town* theTown);
        void setTownTwoPointer(town* theTown);


public:

private:
        int _distance;
        bool _bridge;
        string _townOneString;
        string _townTwoString;
        town * _townOne;
        town * _townTwo;

};
