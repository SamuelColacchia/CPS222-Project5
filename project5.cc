#include "graph.h"

// FILE *_stream;

int numTowns;
int numRoads;
vector <string> fields;
string townInput;
string roadInput;
string regionCapital;

int main(int argc, char const *argv[])
{
  cout << "Project 5" << endl;

  cout << endl;

  //loop looking eof

  //Call create graph

  cout << "(#TOWNS #ROADS)" << endl;

while(true){
  if (cin.eof()) {
    std::cout << "no more Data" << std::endl;
  }
  cin >> numTowns;

  cin >> numRoads;

  cout << "towns:" << numTowns << endl;

  cout << "roads:" << numRoads << endl;

  for (int loopNumTowns = 0; loopNumTowns < numTowns; loopNumTowns++)
  {
    if (loopNumTowns == 0)
    {
      cin >> regionCapital;
      graph.addTown(regionCapital, true);
      cout << "regionCapital:" << regionCapital << endl;

    }
    else
    {
      cin >> townInput;
      cout << "towninput:" << townInput << endl;
      graph.addTown(regionCapital, false);
    }

    //use the created graph to create towns
  }
  getline(cin,roadInput);
  for (int loopNumRoads = 0; loopNumRoads < numRoads; loopNumRoads++)
  {
    split( fields, getline(cin,roadInput);, is_any_of( " " ) );

    string heads = fields[0];
    string tails = feilds[1];
    double distance = feilds[2];
    bool bridge;
    if(fields[3] == B){
      bridge = true;
    }
    else[
      bridge = false;
    ]

    graph.addRoad(heads, tails, distance, bridge);

    cout << "roadinput:" << roadInput << endl;
    //use the created graph to create roads
  }
  getline(cin,roadInput);
}

// while (true)
// {
//   if (cin.eof())
//   {
//     break;
//   }
//   else
//   {
//     cin.unget();
//   }
//   cout << cin << endl;
// }

// ifstream file ("sampledata.data");
// while (getline(file,inputD)) {
//   cout << "current line:" << inputD << endl;
//   cout << "line pos 0:" << inputD[0] << endl;
//   cout << "line length:" << inputD.length() << endl;
// }

// while (!cin.eof())
// {
//   cout <<  "mats method" << inputD << endl;
//   getline(cin,inputD);
// }

// _stream = fopen(testD.c_str(), "r+b");
// if (_stream != NULL)
// {
//   cout << "there is content" << endl;
// }
// else
// {
//   cout << "empty" << endl;
// }
}
