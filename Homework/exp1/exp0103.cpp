#include <bits/stdc++.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b); // 递归求公约数
}

int main()
{
    std::cout << "Please input two num: ";
    int a, b;
    while (std::cin >> a >> b) {
        std::cout << "The gcd num is: " << gcd(a, b) << std::endl;
        // 其实可以直接用std::gcd的
        std::cout << "Please input two num: ";
    }
    return 0;
}