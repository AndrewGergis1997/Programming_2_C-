// TODO: Include your header file of the class describing a series of four colors
/*
 * Name: Andrew Gergis
 * Student number: 150905291
 * UserID: mqange ( Necessary due to gitlab folder naming. )
 * E-Mail: andrew.gergis@tuni.fi
 */
#include "AllColors.hh"
#include <iostream>
#include <vector>
#include <random>
#include <string>


using namespace std;

// Maximum number of guesses
// (Not used in the template code)
//const unsigned int GUESS_MAX = 10; // Not in use, yet



// Length of the suffix part when printing a row.
// The suffix consists of three vertical lines ('|') and two digits, where one
// tells the amount of totally correct colors and the other tells the amount
// of correct colors in incorrect positions.
const unsigned int SUFFIX_LENGTH_IN_PRINT = 5;

// Text printed at the beginning of the program
const string INFO_TEXT = "Colors in use: \
B = Blue, R = Red, Y = Yellow, G = Green, O = Orange, V = Violet";

// TODO: Do you need more constants?

// Reads the input way, either random or listing way,
// and fills the color series in the user-desired way.
// Repeats the question until the user enters either R or L.
bool is_valid = false;

void get_input(AllColors &refrence)
{
    cout << "Enter an input way (R = random, L = list): ";
    string input_str = "";
    cin >> input_str;
    if(input_str == "R" or input_str == "r")
    {
        cout << "Enter a seed value: ";
        int seed = 0;
        cin >> seed;
        refrence.random_generator(seed); // Fill color series randomly based on the seed value
        is_valid = true;
    }
    else if(input_str == "L" or input_str == "l")
    {
        refrence.manual_generator();
        is_valid = true;

    }
    else
    {
        cout << "Bad input" << endl;
        get_input(refrence);
    }
}

// Prints a line consisting of the given character c.
// The length of the line is given in the parameter line_length.
void print_line_with_char(char c, unsigned int line_length)
{
    for(unsigned int i = 0; i < line_length; ++i)
    {
        cout << c;
    }
    cout << endl;
}

// Prints all color series.
// (Not called in the template code.)
void print_all(/* a vector including color series */)
{
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
    //for(/* go through the vector */)
    {
        // TODO: print each vector element (color series)
    }
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
}

// Implements the actual game loop, where user-given guesses are read
// and compared to the secret row.
// On each round, all rows given so far are printed.
void game_start(AllColors user_given_series){
    user_given_series.trials();
}
int main()
{
    cout << INFO_TEXT << endl;
    print_line_with_char('*', INFO_TEXT.size());

    // Declare an object for a color series (the secret one)
    AllColors refrence;
    get_input(refrence);

    // TODO: Play the game, i.e. repeatedly read a user given number series
    // and compare it with the secret one
    AllColors entered_sequence;
    if(is_valid){
            game_start(refrence);
    }


    return 0;
}

