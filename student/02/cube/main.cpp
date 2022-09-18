#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  cout << "Enter a number: ";
  int n;
  int cube = 0;
  cin >> n;
  if (n <= 1289)
    {
        cube = pow (n,3);
        cout <<"The cube of "<< n <<" is " << cube << "." <<endl;
    }
  else
    {
       cube = pow (n,3);
      cout << "Error! The cube of "<< n << "is not "<< cube <<"." << endl;
    }

  return 0;
}
