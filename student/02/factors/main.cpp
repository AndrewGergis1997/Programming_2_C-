#include <iostream>

using namespace std;

void printPFsInPairs(int n)
{
int j=1;
    for (int i = j; i * i <= n; i++)
      {
        if (n % i == 0)
          {
          j = i;
          }
      }
    cout << n << " = " << j << " * " << n / j << endl;
}
int main()
{
    cout << "Enter a positive number: ";

    // Write your code here
    int n;
    cin >> n;
    if (n<=0)
      {
        cout << "Only positive numbers accepted" << endl;
      }
    else
      {
    printPFsInPairs(n);
      }
    return 0;
}
