#include <iostream>
#include <cstdlib>

using namespace std;

int probability( unsigned long int x, unsigned long int y)
{
  int all = x;
  int drawn =  y;
  long int z = all - drawn;
  int c = abs(z);
  for (int i = 1 ; i < all ; i++)
    {
      x *= i;
    }

  for (int j = 1 ; j < drawn ; j++)
    {
      y *= j;
    }

  for (int k = 1 ; k < c ; k++)
    {
      z = abs(z) * k;
    }

  unsigned long int prob = x / ( y * abs(z) )  ;
  return prob;
}

int main()
{
  cout << "Enter the total number of lottery balls: " ;
  long int all;
  cin >> all;

  cout << "Enter the number of drawn balls: ";
  long int drawn;
  cin >> drawn;


 if ( all <=0 || drawn <= 0)
    {
     cout << "The number of balls must be a positive number." << endl;
    }

 else  if ( drawn > all )
   {
     cout << "The maximum number of drawn balls is the total amount of balls." << endl;
   }

  else if ( drawn == all )
    {
      cout << "The probability of guessing all "<< drawn <<" balls correctly is 1/1" << endl;
    }

  else if (all > 0 && drawn > 0)
    {
      cout << "The probability of guessing all "<< drawn <<" balls correctly is 1/"<< probability(all, drawn) << endl;
    }

  return 0;
}
