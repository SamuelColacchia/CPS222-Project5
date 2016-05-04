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
        //createa vector iterator for the roads
        //and a bool array, then set the entire array to false
        vector<road>::iterator roadIt;
        bool scheduled [ _townVector.size() ];
        for (int i = 0; i <  _townVector.size(); i++) {
                scheduled[i] = false;
        }
        //create a queueand push the first number interation and set the first city
        // in schedruled to true
        queue < int > toVisit;
        toVisit.push(0);
        scheduled[0] = true;

        while (!toVisit.empty())
        {
                //get the number to the first town in the queue
                int current = toVisit.front(); toVisit.pop();
                //get the name of that city using the city array
                string currentCity = _townVector[current].getTownName();
                //print the city name
                cout << currentCity <<endl;
                int k = 0;
                //then print out all the towns connected to it
                for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
                {
                        if(currentCity == roadIt->getTownOne()) {
                                cout << roadIt->getTownTwo() << " " << roadIt->getDistance()<< endl;
                        }

                }

                //go through all the roads
                for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
                {
                        //get the names of town one
                        string townOne = roadIt->getTownOne();
                        int i =0;
                        bool search = false;
                        //find the town in the array of towns
                        while(search == false) {
                                if(townOne ==_townVector[i].getTownName()) {
                                        search = true;
                                }
                                else{
                                        i++;
                                }
                        }
                        //sif first time visited set the position of that city to true in
                        //the visited array and push it to toVisist
                        if (!scheduled[i])
                        {
                                toVisit.push(i);
                                scheduled[i] = true;
                        }

                }

        }

}


//jordon helped me(matt) with this, and stack overflow :)
int graph::smallestPath(int D[], list <int> toVisit){
        int smallestPath = toVisit.front();
        if (toVisit.size() > 1) {
                for(int i = 0; i < _townVector.size(); i++) {
                        if(D[smallestPath]>D[i]) {
                                //found this on stack overflow
                                bool found = (std::find(toVisit.begin(), toVisit.end(), i)
                                              != toVisit.end());
                                if (found) {
                                        smallestPath = i;
                                }
                        }
                }
        }
        return smallestPath;
}

void graph::dijkstraMethod(){

        int prev[ _townVector.size() ];

        vector<road>::iterator roadIt;
        list<int>toVisit;
        string townOne;
        string townTwo;
        bool search;
        int D[ _townVector.size() ];

        for (int i = 0; i <  _townVector.size(); i++) {
                D[i] = 100000000;
                toVisit.push_back(i);
        }

        D[0] = 0;


        while (!toVisit.empty()) {
                int smallestDistance = smallestPath(D, toVisit);
                toVisit.remove(smallestDistance);
                std::cout << toVisit.size() << std::endl;

                for(roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++) {

                        townOne = roadIt->getTownOne();
                        townTwo = roadIt->getTownTwo();
                        int i = 0;

                        if(townOne == _townVector[smallestDistance].getTownName()) {

                                search = false;
                                //find the town in the array of towns
                                while(search == false) {
                                        if(townOne ==_townVector[i].getTownName()) {
                                                search = true;
                                        }
                                        else{
                                                i++;
                                        }
                                }

                        }
                        else if( townTwo == _townVector[smallestDistance].getTownName()) {

                                int i =0;
                                search = false;
                                //find the town in the array of towns
                                while(search == false) {
                                        if(townTwo ==_townVector[i].getTownName()) {
                                                search = true;
                                        }
                                        else{
                                                i++;
                                        }
                                }

                        }


                        int newD = D[smallestDistance] + roadIt->getDistance();
                        if (newD < D[i]) {
                                D[i] = newD;
                                prev[i] = smallestDistance;
                        }
                }
        }
        for (int i = 1; i < _townVector.size(); i++) {
                cout << "      " << "The shortest route from " + _townVector[0].getTownName();
                cout << " to " + _townVector[i].getTownName() + " is " << D[i];
                cout << " mi:" << std::endl;

        }
}






// May add this at some point
// void graph::iterate()
// {}
