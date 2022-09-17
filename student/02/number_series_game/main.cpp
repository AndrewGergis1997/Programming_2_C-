#include <iostream>

using namespace std;

int main()
{
    std::cout << "How many numbers would you like to have? ";

    // Write your code here

    int num = 1 ;
    int i;
    cin >>i;
    for ( ; i>=num;num++)
      {
        if ( num % 3 == 0 )
          {
            cout << "zip" << endl;
          }
        else
          {
            cout<<num<< endl;
          }

      }
      return 0;
}
