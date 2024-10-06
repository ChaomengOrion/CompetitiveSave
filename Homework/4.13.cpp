#include <bits/stdc++.h>

int main() {
    std::cin.sync_with_stdio(false);
    float miles = -1, total_miles = 0, total_gallons = 0;
    std::cout << std::fixed << std::setprecision(6) << "Enter miles driven (-1 to quit): ";
    while (std::cin >> miles) {
        if (miles == -1) break;
        total_miles += miles;
        std::cout << "Enter gallons used: ";
        float gallons;
        std::cin >> gallons;
        total_gallons += gallons;
        std::cout << "MPG this trip: " << miles / gallons << "\n"
            << "Total MPG: " << total_miles / total_gallons << "\n\n";
        std::cout << "Enter miles driven (-1 to quit): ";
    }
    return 0;
}