/* COMP.CS.110 Project 2: GIGS
 * ===========================
 * EXAMPLE SOLUTION
 * ===========================
 *
 * Acts as a simple gig calendar with n commands:
 * ARTISTS - Prints all known artist names
 * ARTIST <artist name> - Prints single artist's gigs
 * STAGES - Prints all known stage names and their locations
 * STAGE <stage name> - Prints all artists having a gig at the given stage
 * ADD_ARTIST <artist name> - Adds a new artist
 * ADD_GIG <artist name> <date> <town name> <stage name> - Adds a new gig for
 * an artist with the given date, town, and stage (the artist can't already
 * have a gig on the same date and there can't be other gigs at the same stage
 * at the same time)
 * CANCEL <artist name> <date> - Cancels artist's gigs after the given date
 *
 *  The data file's lines should be in format
 * artist_name;date;town_name;stage_name.
 * Otherwise the program execution terminates instantly (but still gracefully).
 *
 * Name: Andrew Gergis
 * Student number: 150905291
 * UserID: mqange ( Necessary due to gitlab folder naming. )
 * E-Mail: andrew.gergis@tuni.fi
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



// Farthest year for which gigs can be allocated
const std::string FARTHEST_POSSIBLE_YEAR = "2030";

// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split(const std::string& str, char delim = ';')
{
  std::vector<std::string> result = {""};
  bool inside_quotation = false;
  for ( char current_char : str )
    {
      if ( current_char == '"' )
        {
          inside_quotation = not inside_quotation;
        }
      else if ( current_char == delim and not inside_quotation )
        {
          result.push_back("");
        }
      else
        {
          result.back().push_back(current_char);
        }
    }
  if ( result.back() == "" )
    {
      result.pop_back();
    }
  return result;
}

//bool isFormat(std::ifstream & file_obj)
//{
//  std::string line;
//  while (getline(file_obj, line)) {
//      int count = 0;
//      for(uint i=0; i<line.size();i++)
//        {
//          if(line[i] == ';' && line[i+1]==';')
//            return false;
//          if(line[i] == ';')
//            count++;
//        }
//      if(count!= 3)
//        return false;
//    }
//  return true;
//}
// Checks if the given date_str is a valid date, i.e. if it has the format
// dd-mm-yyyy and if it is also otherwise possible date.
bool is_valid_date(const std::string& date_str)
{
  std::vector<std::string> date_vec = split(date_str, '-');
  if ( date_vec.size() != 3 )
    {
      return false;
    }

  std::string year = date_vec.at(0);
  std::string month = date_vec.at(1);
  std::string day = date_vec.at(2);
  std::vector<std::string> month_sizes
      = { "31", "28", "31", "30", "31", "30",
          "31", "31", "30", "31", "30", "31" };

  if ( month < "01" or month > "12" )
    {
      return false;
    }
  if ( year < "0001" or year > FARTHEST_POSSIBLE_YEAR )
    {
      return false;
    }
  unsigned int year_int = stoi(year);
  bool is_leap_year = (year_int % 400 == 0) or
      (year_int % 100 != 0 and year_int % 4 == 0);
  if ( day >= "01" and
       (day <= month_sizes.at(stoi(month) - 1) or
        (month == "02" and is_leap_year and day <= "29")) )
    {
      return true;
    }
  else
    {
      return false;
    }
}


//struct Gig{
//  string artist,
//  date,
//  city,
//  stage;
//};

set <string> readArtistDataFromFile (ifstream &file)
{
  set <string> artistData;
  string line;
  vector <string> dataItems;
  while(getline(file, line))
    {
      dataItems = split (line);
      artistData.insert(dataItems.at(0));
    }
  return artistData;
}


set <string> readDateDataFromFile (ifstream &file)
{
  set <string> dateData;
  string line;
  vector <string> dataItems;
  while(getline(file, line))
    {
      dataItems = split (line);
      dateData.insert(dataItems.at(1));
    }
  return dateData;
}

set <string> readCityDataFromFile (ifstream &file)
{
  set <string> cityData;
  string line;
  vector <string> dataItems;
  while(getline(file, line))
    {
      dataItems = split (line);
      cityData.insert(dataItems.at(2));
    }
  return cityData;
}

set <string> readStageDataFromFile (ifstream &file)
{
  set <string> stageData;
  string line;
  vector <string> dataItems;
  while(getline(file, line))
    {
      dataItems = split (line);
      stageData.insert(dataItems.at(3));
    }
  return stageData;
}

void printArtist (set <string>  &gig)
{
  for (auto & itr : gig)
    {
      cout << itr << endl;
    }
}

//set<int> convertToSet(vector<int> v)
//{
//  // Declaring the set
//  set<int> s;

//  // Traverse the Vector
//  for (int x : v) {

//      // Insert each element
//      // into the Set
//      s.insert(x);
//    }

//  // Return the resultant Set
//  return s;
//}


int main()
{
  set <string> artistData;
  string inFile = "";
  cout << "Give a name for input file: ";         // input file name
  getline(cin, inFile);

  ifstream fileRead(inFile);      // creating file to read from it

  if ( not fileRead ) {           // check for input file errors
      cout << "Error: File could not be read."<< endl;
      return EXIT_FAILURE;
    }
  //  else if (not isFormat(fileRead))
  //    {
  //      return EXIT_FAILURE;
  //    }
  // reading data into a file structure
  artistData=readArtistDataFromFile (fileRead);
  // print first item

  //  set <string> artists = convertToSet(gigData.at(0));

  string command;
  while (command != "QUIT" || command != "quit")
    {

      cout<<"gigs>";
      getline(cin,command);

      if (command == "ARTISTS" || command == "artists")
        {
          cout<< "All artists in alphabetical order:"<<endl;

          printArtist(artistData);

        }

    }
  return EXIT_SUCCESS;
}
