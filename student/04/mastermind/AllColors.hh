#ifndef ALLCOLORS_H
#define ALLCOLORS_H
#include <vector>
#include<string>


enum color {b,r,y,g,o,v};

// Fixed colors size
const unsigned int SIZE = 4;

class AllColors
{
public:
    AllColors();
    int get_current_position( );
    int get_correct_colors( );
    void random_fill_color(int&);
    void user_refrence_colors();
    void fill_series_manually();
    void user_refrence_colors_trial();
    void trials();
    bool check_colors();
    bool check_length();
    bool check_colors_trial();
    bool check_length_trial();
    void print_all_trials(std::vector<std::string>);

private:

    std::string entered_colors;
    std::string refrence_colors;
};

#endif // ALLCOLORS_H
