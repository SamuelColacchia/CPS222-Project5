#include "graph.h"

int numTowns;
int numRoads;
vector<string> fields;
string townInput;
string roadInput;
string regionCapital;

int roadInputSize;

int roadInputT1Pos;
int roadInputT2Pos;
int roadInputBridgePos;
int roadInputDistPos;

int endNull;

char roadT1;
string roadT2;
string roadBridge;
string roadDist;

int main()
{
  cout << "Project 5" << endl;

  cout << endl;

  //loop looking eof

  //Should find a good way to distigesh between graphs
  graph theGraph;

  cout << "(#TOWNS #ROADS)" << endl;

  while (true)
  {
    if (cin.eof())
    {
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

        cout << "regionCapital:" << regionCapital << endl;

        theGraph.addTown(regionCapital, true);

      }
      else
      {
        cin >> townInput;
        cout << "towninput:" << townInput << endl;
        theGraph.addTown(regionCapital, false);
      }

      //use the created graph to create towns
    }
    getline(cin,roadInput);
    for (int loopNumRoads = 0; loopNumRoads < numRoads; loopNumRoads++)
    {
      // split( fields, getline(cin,roadInput), is_any_of( " " ));
      //
      // string heads = fields[0];
      // string tails = feilds[1];
      // double distance = feilds[2];
      // bool bridge;
      // if(fields[3] == B){
      //   bridge = true;
      // }
      // else[
      //   bridge = false;
      // ]

      // roadInput.find(' ')

      roadInputSize = roadInput.size();

      for (int roadPos = 0; roadInputSize > roadPos; roadPos++)
      {
        if (roadInput[roadPos] == ' ') {
          roadInputT1Pos = roadPos;
          endNull = roadInput.copy(roadT1, 0, roadInputT1Pos);

          roadT1[endNull] = '\n';
          roadPos++;
        }
        else if (roadInput[roadPos] == ' ') {
          roadInputT2Pos = roadPos;
          roadPos++;
        }
        else if (roadInput[roadPos] == ' ') {
          roadInputBridgePos = roadPos;
          roadPos++;
        }
        else if (roadInput[roadPos] == ' ') {
          roadInputDistPos = roadPos;
          roadPos++;
        }
      }


      cout << "T1:" << roadT1 << endl;
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
