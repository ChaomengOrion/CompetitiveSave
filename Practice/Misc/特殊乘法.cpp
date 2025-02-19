#include <bits/stdc++.h>

int cal(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        std::cout << cal(a) * cal(b) << std::endl;
    }
}