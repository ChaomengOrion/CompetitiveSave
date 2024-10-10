#include <bits/stdc++.h>

int main()
{
    double amount;
    double principle = 1000.0;
    double rate = .05;
    std::cout << "Please enter rate:";
    while (std::cin >> rate) {
        for (int year = 1; year <= 10; year++) {
            std::cout << "Year" << std::setw(21) << "Amount on despoit" << std::endl;
            amount = principle * pow(1.0 + rate, year);
            std::cout << std::setw(4) << year << std::setw(21) << amount << std::endl;
        }
        std::cout << "Please enter rate:";
    }
}