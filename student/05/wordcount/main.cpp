#include <iostream>
#include <fstream>
#include<map>
#include<set>

using namespace std;

int main()
{
  //gettig filename

  cout << "Input file:";

  string filename;
  getline(cin, filename);

  //try opening
  ifstream file(filename);


  if (!file)
    {
      cout << "Error! The file"<<filename
           <<"cannot be opened."
           <<endl;
      return EXIT_FAILURE;
    }

  map<string,pair <int,set<int>>> words;
  string line;
  while (getline(file, line))
    {

    }

}
