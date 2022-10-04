#include "AllColors.hh"
#include<random>
#include <iostream>
#include <string>
#include <cctype>

AllColors::AllColors()
{

}

/* printing the old trials and the last trial of user */
void AllColors::print_all_trials(std::vector<std::string> trialsHistory){

  std::cout<< "==================="<<std::endl;
  for (int i=0; i< (int)trialsHistory.size();i++)
    {
     std::cout << trialsHistory.at(i) << std::endl;
    }
  std::cout<< "==================="<<std::endl;
}

/*first cehcking of correct color && correct place*/
int AllColors::get_current_position( ) {
  int correctPosition = 0;
  for (int i=0; i < (int) SIZE ;i++)
  {
     if(entered_colors.at(i) == refrence_colors.at(i))
      {
         correctPosition++;
      }

  }
  return correctPosition;
}
/*second checking getting all correct colors
then subtracting this function out from the first
checking function out to get
  Correct  colors in wrong Positioon*/
  int AllColors::get_correct_colors( ) {
  int correctColor = 0;
  std::string temp = refrence_colors;
  for (int i=0; i < (int) SIZE ;i++)
  {
      for (int j=0; j < (int)SIZE ; j++ )
        {
          if(entered_colors.at(i) == temp.at(j))
            {
              temp[j]='x';
              correctColor++;
              break;
            }
        }

  }
  return correctColor;
}


/* Generating Random colors to fill vector entered_colors (Works with R choice)*/
void AllColors::random_generator(int & seed)
{

        std::vector<char> color {'b', 'r', 'y', 'g', 'o', 'v'};
        static std::uniform_int_distribution<int> distr(b, v); // sitting boundaries from b to v
        static std::default_random_engine gen(seed);
        for (uint i= 0; i < SIZE; i++) // adding generated colors to the vector
        {
            int d =distr(gen);
            refrence_colors.push_back(color.at(d));// pushing colors in the vector
        }

}

/*intaking refrence color sequence from user*/
void AllColors::user_refrence_colors()
{
  std::cin >> refrence_colors;

}

/* Checking if the given refrence color sequence is in available colors and in right size (Works with L choice)*/
void AllColors::manual_generator()
{

    bool accepted = false;
    for(;not accepted ;)
    {
    std::cout << "Enter four colors (four letters without spaces): ";
    user_refrence_colors();
    if(check_length())
        {
            if(check_colors())
               {
                  accepted = true;
               }
            else { std::cout << "Unknown color"<< std::endl;}
        }
    else
        {
          std::cout << "Wrong size"<< std::endl;
        }

    }
}


/*intaking trials color sequence from user*/
void AllColors::user_refrence_colors_trial()
{
  std::cout << "ROW> ";
  std::cin >> entered_colors;
  if (entered_colors == "q" || entered_colors == "Q")
      {
      exit(EXIT_FAILURE);
      }

  }

/* Checking if the entered user color sequence is in available colors and in right size*/
void AllColors::trials()
{
    std::vector<std::string> trialsHistory;
    bool accepted = false;
    for(int i=1 ;not accepted && i<=10; i++ )
    {
    user_refrence_colors_trial();
    if(check_length_trial())
        {
            if(check_colors_trial())
               {
                  int currentPos = get_current_position( );
                  int colorXpos = get_correct_colors( ) - currentPos;
                  if (currentPos == 4)
                    {
                      accepted = true;
                    }
                  std::string x = "";
                  for (int i=0; i<(int)entered_colors.size();i++)
                    {
                      x += toupper(entered_colors.at(i));
                      x += " ";
                    }
                  trialsHistory.push_back("| "+x+"| "+std::to_string(currentPos)+" | "+std::to_string(colorXpos)+" |");
                  print_all_trials(trialsHistory);
               }
            else { std::cout << "Unknown color"<< std::endl;}
        }
    else
        {
          std::cout << "Wrong size"<< std::endl;
        }

    }
   if (accepted)
     {
       std::cout << "You won: Congratulations!"<<std::endl;
     }
   else
       std::cout << "You lost: Maximum number of guesses done"<<std::endl;
}


/*checking if the refrence colors are legal*/
bool AllColors::check_colors(){
    std::string given_colors = "brygov";
    int i=0;
        for (char c : refrence_colors)
        {

            for(char d: given_colors)
            {
            if(c==d)
                 i++;
            }

        }
        return i==4;

}

/* checking size of refrence colors*/
bool AllColors::check_length()
{
    return (refrence_colors.length() == SIZE);
}


/*checking if the entered colors are legal*/
bool AllColors::check_colors_trial(){
    std::string given_colors = "brygov";
    int i=0;
        for (char c : entered_colors)
        {

            for(char d: given_colors)
            {
            if(c==d)
                 i++;
            }

        }
        return i==4;

}

/* checking size of entered colors*/
bool AllColors::check_length_trial()
{
    return (entered_colors.length() == SIZE);
}
