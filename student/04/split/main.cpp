#include <iostream>
#include <string>
#include <vector>


// TODO: Implement split function here
// Do not change main function
std::vector<std::string> split(const std::string &line,
                               const char sep,
                               bool ignore_empty = false)
{
  std::vector<std::string> parts = {};
  std::string part = "";

  for(char c : line)
    {
      // checking separate or not
      if(c == sep)
        {
          //checking empty
          if (!(part.empty() &&  ignore_empty))
            {
              parts.push_back(part);
            }
          part.clear();
        }
      else{
          part = part + c;
        }
    }
  parts.push_back(part);
  return parts;
}
int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( const std::string &part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( const std::string & part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
