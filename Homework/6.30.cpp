#include <iostream>

using namespace std;

// Function to reverse the digits of an integer
int reverseDigits(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    int reversedNumber = reverseDigits(number);
    cout << "The number with its digits reversed is: " << reversedNumber << endl;

    return 0;
}