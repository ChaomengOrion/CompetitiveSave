#include <iostream>

using namespace std;

// Function to find the smallest of three double-precision floating-point numbers
double findSmallest(double num1, double num2, double num3) {
    double smallest = num1;
    if (num2 < smallest) {
        smallest = num2;
    }
    if (num3 < smallest) {
        smallest = num3;
    }
    return smallest;
}

int main() {
    double num1, num2, num3;
    cout << "Enter three double-precision floating-point numbers: ";
    cin >> num1 >> num2 >> num3;

    double smallest = findSmallest(num1, num2, num3);
    cout << "The smallest number is: " << smallest << endl;

    return 0;
}