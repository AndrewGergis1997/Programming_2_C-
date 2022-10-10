#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{ 
  string inFile = "";
      cout << "Input file: ";         // input file name
      getline(cin, inFile);
      ifstream fileRead(inFile);      // creating file to be read from

  string outFile = "";
      cout << "Output file: ";        // output file name
      getline(cin, outFile);
      ofstream fileWrite(outFile);    // creating file to be writen into

      if ( not fileRead ) {           // check for input file errors
          cout << "Error! The file not_a_file.input cannot be opened." << endl;
          return EXIT_FAILURE;
      } else {

          string line;
          string temp;
          for(int i = 1 ;getline(fileRead, line); i++ ) {   // reading input file line by line
             temp = to_string(i) + " " + line;              // adding number and space before line
             fileWrite << temp <<endl;                      // writting modefied input file contents into output file
          }
          fileRead.close();    // close input file
          fileWrite.close();   // close output file

      }
      return 0;
}
