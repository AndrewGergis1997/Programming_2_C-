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
const string FARTHEST_POSSIBLE_YEAR = "2030";

// Casual split func, if delim char is between "'s, ignores it.
 vector<string> split(const string& str, char delim = ';')
{
  vector<string> result = {""};
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

bool isFormat(ifstream & file_obj)
{
  string line;
  while (getline(file_obj, line)) {
      int count = 0;
      for(uint i=0; i<line.size();i++)
        {
          if(line[i] == ';' && line[i+1]==';')
            return false;
          if(line[i] == ';')
            count++;
        }
      if(count!= 3)
        return false;
    }
  file_obj.close();
  return true;
}
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

set <string> readArtistDataFromFile (ifstream &file1)
{
  set <string> artistData;
  string line;
  vector <string> dataItems;
  while(getline(file1, line))
    {
      dataItems = split (line);
      artistData.insert(dataItems.at(0));
    }
  file1.close();
  return artistData;
}


set <string> readDateDataFromFile (ifstream &file2)
{
  set <string> dateData;
  string line;
  vector <string> dataItems;
  while(getline(file2, line))
    {
      dataItems = split (line);
      dateData.insert(dataItems.at(1));
    }
  file2.close();
  return dateData;
}

set <string> readCityDataFromFile (ifstream &file3)
{
  set <string> cityData;
  string line;
  vector <string> dataItems;
  while(getline(file3, line))
    {
      dataItems = split (line);
      cityData.insert(dataItems.at(2));
    }
  file3.close();
  return cityData;
}

set <string> readStageDataFromFile (ifstream &file4)
{
  set <string> stageData;
  string line;
  vector <string> dataItems;
  while(getline(file4, line))
    {
      dataItems = split (line);
      stageData.insert(dataItems.at(3));
    }
  file4.close();
  return stageData;
}

void printArtist (set <string>  &gig)
{
  for (auto & itr : gig)
    {
      cout << itr << endl;
    }
}

void printDate (set <string>  &gig)
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

bool checkDate (ifstream &file2)
{
  set <string> dateData;
  string line;
  vector <string> dataItems;
  while(getline(file2, line))
    {
      dataItems = split (line);
      if (!is_valid_date(line))
        {
          return true;
        }
      dateData.insert(dataItems.at(1));
    }
  file2.close();
  return false;
}

int main()
{
  set <string> artistData;
  set <string> artistDate;
  set <string> artistCity;
  set <string> artistStage;
  string inFile = "";
  cout << "Give a name for input file: ";         // input file name
  getline(cin, inFile);

  // creating files to read from it
  ifstream fileRead(inFile);
  ifstream file1(inFile);
  artistData=readArtistDataFromFile (file1);
  ifstream file2(inFile);
  artistDate=readDateDataFromFile(file2);
  ifstream file3(inFile);
  artistCity=readCityDataFromFile(file3);
  ifstream file4(inFile);
  artistStage=readStageDataFromFile(file4);

  // check for input file errors
  if ( not fileRead ) {
      cout << "Error: File could not be read."<< endl;
      return EXIT_FAILURE;
    }

  // check for format file errors
  else if (not isFormat(fileRead))
    {
      cout << "Error: Invalid format in file."<< endl;
      return EXIT_FAILURE;
    }
  // check for date data errors
  else if (not checkDate(file2))
    {
      cout << "Error: Invalid date."<< endl;
      return EXIT_FAILURE;
    }
  //   reading data into a file structure



  //  set <string> artists = convertToSet(gigData.at(0));

  string command;
  while (command != "QUIT")
    {
      cout << "gigs> ";
      getline(std::cin, command);
      for (auto & c: command)
        {
          c = toupper(c);
        }
      if (command == "ARTISTS" || command == "artists")
        {
          cout<< "All artists in alphabetical order:"<<endl;
          printArtist(artistData);
          printDate(artistDate);
        }
    }
  fileRead.close();
  file1.close();
  file2.close();
  file3.close();
  file4.close();

  return EXIT_SUCCESS;
}
