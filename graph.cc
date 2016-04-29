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


void graph::bfs()
{

        vector<road>::iterator roadIt;
        bool scheduled [ _townVector.size() ];
        for (int i = 0; i <  _townVector.size(); i++) {
                scheduled[i] = false;
        }

        queue < int > toVisit;
        toVisit.push(0);
        scheduled[0] = true;

        while (!toVisit.empty())
        {
                int current = toVisit.front(); toVisit.pop();
                string currentCity = _townVector[current].getTownName();
                cout << currentCity <<endl;
                int k = 0;
                for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
                {
                        if(currentCity == roadIt->getTownOne()) {
                                cout << roadIt->getTownTwo() << " " << roadIt->getDistance()<< endl;
                        }

                }


                for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
                {
                        string townOne = roadIt->getTownOne();
                        int i =0;
                        bool search = false;
                        while(search == false) {
                                if(townOne ==_townVector[i].getTownName()) {
                                        search = true;
                                }
                                else{
                                        i++;
                                }
                        }
                        if (!scheduled[i])
                        {
                                toVisit.push(i);
                                scheduled[i] = true;
                        }

                }

        }

}



// May add this at some point
// void graph::iterate()
// {}
