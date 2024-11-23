#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to add two large numbers represented as strings
string addLargeNumbers(string num1, string num2) {
    // Ensure num1 is the longer number
    if (num1.length() < num2.length()) {
        swap(num1, num2);
    }

    // Reverse both numbers to facilitate addition from least significant digit
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result;
    int carry = 0;
    for (size_t i = 0; i < num1.length(); ++i) {
        int digit1 = num1[i] - '0';
        int digit2 = (i < num2.length()) ? num2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    // If there is a carry left, add it to the result
    if (carry) {
        result.push_back(carry + '0');
    }

    // Reverse the result to get the final sum
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    cout << "Enter the first large number: ";
    cin >> num1;
    cout << "Enter the second large number: ";
    cin >> num2;

    string sum = addLargeNumbers(num1, num2);
    cout << "The sum of the two large numbers is: " << sum << endl;

    return 0;
}