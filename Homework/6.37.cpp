#include <iostream>
#include <limits>

using namespace std;

// Function to calculate the nth Fibonacci number using int
int fibonacciInt(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Function to calculate the nth Fibonacci number using double
double fibonacciDouble(int n) {
    if (n <= 1) return n;
    double a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    // Part (a): Using int
    cout << "Fibonacci numbers using int:\n";
    int n = 0;
    while (true) {
        int fib = fibonacciInt(n);
        if (fib < 0) break; // Overflow detected
        cout << "Fibonacci(" << n << ") = " << fib << endl;
        ++n;
    }
    cout << "The largest int Fibonacci number is Fibonacci(" << n-1 << ") = " << fibonacciInt(n-1) << endl;

    // Part (b): Using double
    cout << "\nFibonacci numbers using double:\n";
    n = 0;
    while (true) {
        double fib = fibonacciDouble(n);
        if (fib == numeric_limits<double>::infinity()) break; // Overflow detected
        cout << "Fibonacci(" << n << ") = " << fib << endl;
        ++n;
    }
    cout << "The largest double Fibonacci number is Fibonacci(" << n-1 << ") = " << fibonacciDouble(n-1) << endl;

    return 0;
}