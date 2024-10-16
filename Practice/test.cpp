#include <iostream>
#include <cmath>
using namespace std;
int a = 0; // initicialize the variable a to 0
int b = 0; // initicialize the variable b to 0
int x = 0; // initicialize the variable x to 0
int i = 0; // initicialize the variable i to 0
int main()
{
    cout << "Enter the first integer: "; // prompt the user to enter the first integer as a
    cin >> a;
    cout << "Enter the second integer: "; // prompt the user to enter the second integer as b
    cin >> b;
    x = min(a, b);
    for ( i = 1; i <= x; i++ )
    {
        cout << i << endl;
        if( a % i == 0 && b % i == 0 ) {
            cout << i << endl;
            x = i;
        }
    }
    cout << "The greatest common divisor of a and b is: " << x;
}