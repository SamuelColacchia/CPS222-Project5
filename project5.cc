#include "graph.h"

// FILE *_stream;

int numTowns;
int numRoads;
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
    }
    else
    {
      cin >> townInput;
      cout << "towninput:" << townInput << endl;
    }

    //use the created graph to create towns
  }


  getline(cin,roadInput);
  for (int loopNumRoads = 0; loopNumRoads < numRoads; loopNumRoads++)
  {
    getline(cin,roadInput);
    cout << "roadinput:" << roadInput << endl;
    //use the created graph to create roads
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
