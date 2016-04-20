#include "graph.h"

// FILE *_stream;

char something;

int main(int argc, char const *argv[])
{
  cout << "Project 5" << endl;
  while (true)
  {
    cin.get();
    cin >> something;

    if (cin.eof())
    {
      break;
    }
    else
    {
      cin.unget();
    }


    cout << "Echo input:" << something << endl;
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
