#include "graph.h"

// FILE *_stream;

int numTowns;
int numRoads;
string townInput;
string roadInput;

int main(int argc, char const *argv[])
{
  cout << "Project 5" << endl;

  cout << endl;

  cout << "(#TOWNS #ROADS)" << endl;

  cin >> numTowns;

  cin >> numRoads;

  cout << "towns:" << numTowns << endl;

  cout << "roads:" << numRoads << endl;

  for (int loopNumTowns = 0; loopNumTowns < numTowns; loopNumTowns++)
  {
    cin >> townInput;
    cout << "towninput:" << townInput << endl;
  }


  getline(cin,roadInput);
  for (int loopNumRoads = 0; loopNumRoads < numRoads; loopNumRoads++)
  {
    
    getline(cin,roadInput);
    cout << "roadinput:" << roadInput << endl;
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
