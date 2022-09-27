#include "player.h"

Player::Player(std::string const &name):
  points_(0),name_(name)
{

}

std::string Player::get_name() const
{
  return name_;
}

int Player::get_points() const
{
  return points_;
}

void Player::add_points(int points)
{
  points_ += points;
  //checking points limit
  if (points_ > MAX_SCORE)
      points_ = HALF_WAY;

}

bool Player::has_won()
{
  return points_ == MAX_SCORE;
}
