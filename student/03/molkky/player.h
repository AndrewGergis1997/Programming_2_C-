#ifndef PLAYER_H
#define PLAYER_H

#include <string>

const int MAX_SCORE=50,
          HALF_WAY= 25;


class Player
{
public:
  Player(std::string const &name);
  std::string get_name() const;
  int get_points() const;
  void add_points(int points);
  bool has_won();

private:
  int points_;
  std::string name_;
};

#endif // PLAYER_H
