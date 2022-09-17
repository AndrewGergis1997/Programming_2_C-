 #include <iostream>

using namespace std;

int main()
{
    cout << "Enter a temperature: ";

    // Write your code here
    float temp;
    cin  >> temp;
    float cel = (temp * 1.8) + 32;
    float feh = (temp - 32) / 1.8;
    cout << temp <<" degrees Celsius is "<< cel <<" degrees Fahrenheit "<< endl;
    cout << temp <<" degrees Fahrenheit is " << feh << " degrees Celsius"<< endl;

    return 0;
}
