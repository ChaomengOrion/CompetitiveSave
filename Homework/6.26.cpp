#include <iostream>
#include <iomanip>

using namespace std;

// Function to convert Fahrenheit to Celsius
double celsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
double fahrenheit(int celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

int main() {
    cout << fixed << setprecision(2);

    // Print Celsius to Fahrenheit chart
    cout << "Celsius to Fahrenheit conversion chart:\n";
    cout << "Celsius\tFahrenheit\n";
    for (int c = 0; c <= 100; ++c) {
        cout << c << "\t" << fahrenheit(c) << "\n";
    }

    cout << "\n";

    // Print Fahrenheit to Celsius chart
    cout << "Fahrenheit to Celsius conversion chart:\n";
    cout << "Fahrenheit\tCelsius\n";
    for (int f = 32; f <= 212; ++f) {
        cout << f << "\t\t" << celsius(f) << "\n";
    }

    return 0;
}