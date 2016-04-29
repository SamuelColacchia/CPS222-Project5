#include "graph.h"

graph::graph()
{
}


void graph::addTown(string name, bool capital)
{

        town theTown(name, capital);
        _townVector.push_back(theTown);
}


void graph::addRoad(string townOneString, string townTwoString, int distance, bool bridge)
{
        road theRoad(townOneString, townTwoString, distance, bridge);

        _roadVector.push_back(theRoad);
}


//Loop through the vectors connecting all roads and town
void graph::connectRoadsTowns()
{
        string TownOne;
        string TownTwo;

        string currentTown;

        vector<road>::iterator roadIt;
        vector<town>::iterator townIt;
        for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
        {
                TownOne = roadIt->getTownOne();
                TownTwo = roadIt->getTownTwo();

                for (townIt = _townVector.begin(); townIt != _townVector.end(); townIt++)
                {
                        currentTown = townIt->getTownName();

                        if (currentTown == TownOne)
                        {
                                roadIt->setTownOnePointer(&*townIt);
                                townIt->addRoadPointer(&*roadIt);
                        }
                        else if (currentTown == TownTwo)
                        {
                                roadIt->setTownTwoPointer(&*townIt);
                                townIt->addRoadPointer(&*roadIt);
                        }
                }

        }
}


void graph::printTest()
{
        vector <town>::iterator it;
        for (it = _townVector.begin(); it != _townVector.end(); it++)
        {
                cout << it->getTownName() << endl;
        }
}


void graph::bfs(int start){

        string TownOne;
        string TownTwo;

        bool scheduled [ _townVector.size() ];
        for (int i = 0; i <  _townVector.size(); i++) {
                scheduled[i] = false
        }

        queue < int > toVisit;
        toVisit.push(start);
        scheduled[start] = true

        while (! toVisit.empty())
        {
                 int current = toVisit.front(); toVisit.pop()
                 cout<< _townVector[current].getTownName();<<endl;
                 for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
                 {
                         TownOne = roadIt->getTownOne();
                 }

        }

}



// May add this at some point
// void graph::iterate()
// {}
