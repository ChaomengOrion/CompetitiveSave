#include <iostream>
#include <iomanip>

using namespace std;

double calculateCharges(double hours) {
    if (hours <= 3.0) {
        return 2.00;
    } else if (hours <= 24.0) {
        double charge = 2.00 + 0.50 * (hours - 3.0);
        return (charge > 10.00) ? 10.00 : charge;
    }
    return 10.00; // Maximum charge for 24 hours
}

int main() {
    double hours1, hours2, hours3;
    cout << "Enter hours parked for car 1: ";
    cin >> hours1;
    cout << "Enter hours parked for car 2: ";
    cin >> hours2;
    cout << "Enter hours parked for car 3: ";
    cin >> hours3;

    double charge1 = calculateCharges(hours1);
    double charge2 = calculateCharges(hours2);
    double charge3 = calculateCharges(hours3);
    double totalHours = hours1 + hours2 + hours3;
    double totalCharges = charge1 + charge2 + charge3;

    cout << fixed << setprecision(2);
    cout << "Car\tHours\tCharge\n";
    cout << "1\t" << hours1 << "\t" << charge1 << "\n";
    cout << "2\t" << hours2 << "\t" << charge2 << "\n";
    cout << "3\t" << hours3 << "\t" << charge3 << "\n";
    cout << "TOTAL\t" << totalHours << "\t" << totalCharges << "\n";

    return 0;
}