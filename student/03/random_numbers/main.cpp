#include <iostream>
#include <random>
#include <string>

using namespace std;

void produce_random_numbers(unsigned int lower, unsigned int upper, int seed)
{
    // Implement your function here
  default_random_engine gen(seed);
  uniform_int_distribution<int> distr(lower, upper);
  cout <<"Your drawn random number is " << distr(gen) << std::endl;
  char choice;
  cout << "Press q to quit or any other key to continue: ";
  cin >> choice;
  cout <<endl;
      for (;choice != 'q';){
      cout <<"Your drawn random number is " << distr(gen) << std::endl;
      cout << "Press q to quit or any other key to continue: ";
      cin >> choice ;
      cout <<endl;
        }


}

int main()
{
    unsigned int lower_bound, upper_bound;
    int seed;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;

    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound"
             << endl;
        return EXIT_FAILURE;
    }
    else {
    cout << "Enter a seed value: ";
    cin >> seed;
    cout <<endl;

    produce_random_numbers(lower_bound, upper_bound, seed);

    return EXIT_SUCCESS;
      }
}
