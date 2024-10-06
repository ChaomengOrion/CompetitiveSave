#include <bits/stdc++.h>

int main() {
    std::cin.sync_with_stdio(false);
    float hours = -1;
    std::cout << std::fixed << std::setprecision(2) << "Enter hours worked (-1 to quit): ";
    while (std::cin >> hours) {
        if (hours == -1) break;
        std::cout << "Enter hourly rate of the employee ($00.00): ";
        float rate;
        std::cin >> rate;
        if (hours > 40) hours += (hours - 40) / 2;
        std::cout << "Salary is $ " << rate * hours << "\n\n";
        std::cout << "Enter miles driven (-1 to quit): ";
    }
    return 0;
}