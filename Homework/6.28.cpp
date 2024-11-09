#include <iostream>
#include <vector>

bool isPerfect(int number) {
    int sum = 0;
    std::vector<int> divisors;
    for (int i = 1; i <= number / 2; ++i) {
        if (number % i == 0) {
            sum += i;
            divisors.push_back(i);
        }
    }
    if (sum == number) {
        std::cout << number << " is a perfect number. Divisors: ";
        for (int divisor : divisors) {
            std::cout << divisor << " ";
        }
        std::cout << std::endl;
        return true;
    }
    return false;
}

int main() {
    std::cout << "Perfect numbers between 1 and 1000:" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        isPerfect(i);
    }

    // Uncomment the following lines to test numbers much larger than 1000
    // std::cout << "Testing larger numbers:" << std::endl;
    // for (int i = 1001; i <= 10000; ++i) {
    //     isPerfect(i);
    // }

    return 0;
}