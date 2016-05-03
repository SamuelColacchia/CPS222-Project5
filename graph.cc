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


void graph::dijkstraMethod(){

        queue<int>distance;
        stack<string>townName;
        queue<string>path;
        stack<string>targets;


        string currentTown;
        int u;

        vector <town>::iterator it;
        vector<road>::iterator roadIt;

        for (it = _townVector.begin(); it != _townVector.end(); it++)
        {
                if(it->checkCapital() == true) {
                        currentTown = it->getTownName();
                }
                else{
                        targets.push(it->getTownName());
                }
        }

        cout<<"dijkstraMethod"<<endl;
        while(!targets.empty()) {

                path.push(currentTown);

                while(targets.top() != currentTown) {



                        for (roadIt = _roadVector.begin(); roadIt != _roadVector.end(); roadIt++)
                        {
                                //get the names of town one
                                u = 1000;
                                string townOne = roadIt->getTownOne();
                                string townTwo = roadIt->getTownTwo();
                                if(townOne == currentTown || townTwo == currentTown ) {
                                        if(roadIt->getDistance()<u) {

                                                u = roadIt->getDistance();

                                                if(townOne == currentTown) {
                                                        townName.push(roadIt->getTownTwo());
                                                }

                                                else if(townTwo == currentTown) {
                                                        townName.push(roadIt->getTownOne());
                                                        std::cout << "/* check1 */" << roadIt->getTownOne()<< std::endl;
                                                }
                                        }

                                }



                        }

                        currentTown = townName.top();

                        while(!townName.empty()) {
                                townName.pop();
                        }
                        distance.push(u);

                        std::cout << "/* check2 */" << std::endl;


                }
                while(!path.empty()) {
                        cout<<path.front()<< " " <<distance.front()<<endl;
                        path.pop();
                        distance.pop();
                }
                targets.pop();


                std::cout << "/* check3 */" << std::endl;
        }

}


// May add this at some point
// void graph::iterate()
// {}
