#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

 vector<string> ParseString(ifstream &readFile){
     vector<string> result;
     string line="";
    while(getline(readFile,line)){
         result.push_back(line);
     }
    return result;
 }


bool compare(string x, string y)
{
    for (int i = 0; i < (int) min(x.size(), y.size()); i++) {
        if (x[i] == y[i])
            continue;
        return x[i] < y[i];
    }
    return x.size() < y.size();
}
string getName (string name){
    string result="";

    for(char i : name)
        if(i==':')
            break;
        else
            result += i;
    return result;
}
int getScore (string score){
    int result=0;
    bool flag = false;
    for(char i : score){
        result*=10;
        if(i==':')
            flag = true;
        else if(flag==true)
            result += i - '0';
    }
    return result;
}

int main()
{
  string inFile = "";
      cout << "Input file: ";         // input file name
      getline(cin, inFile);
      ifstream fileRead(inFile);      // creating file to be read from

      if ( not fileRead ) {           // check for input file errors
          cout << "Error! The file "<< inFile <<" cannot be opened." << endl;
          return EXIT_FAILURE;

      } else {
             vector<string> playersScores =  ParseString(fileRead);
             cout << "Final scores:" <<endl;
             map<string, int> players;
             for(string &i : playersScores){
                 string name = getName(i);
                 int score = getScore(i);
                 if(players.find(name)!=players.end()){
                     score += players[name];
                 }
                 players[name]=score;
             }

             std::vector<string> playerName;
             for(std::map<string,int>::iterator it = players.begin(); it != players.end(); ++it)
                 playerName.push_back(it->first);

             sort(playerName.begin(), playerName.end(), compare);

             for(string &i : playerName){
                 int score = players[i];
                 cout << i << ": " << score << endl;
             }

             return EXIT_SUCCESS;


                fileRead.close();    // close input file
          }


return 0;
      }


