#include <bits/stdc++.h>

// 质数筛模板
bool isPrime(int num)
{
    if (num == 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    int tmp = sqrt(num);
    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

bool isGreatN(int n) {
    if (n <= 0) return false;
    double sqn = sqrt(n);
    if (sqn != floor(sqn)) {
        return false;
    }
    while (n > 0) {
        int cur = n % 10;
        n /= 10;
        if (!isPrime(cur)) return false;
    }
    return true;
}

int main() {
    int num;
    std::cin >> num;
    std::cout << (isGreatN(num) ? "Yes" : "No") << std::endl;
}