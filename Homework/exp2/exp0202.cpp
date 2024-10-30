#include <bits/stdc++.h>

using i64 = long long;

i64 pow(i64 a, i64 b)
{
    if (b == 0) return 1;
    i64 res = pow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main() {
    std::cout << pow(2LL, 0LL) << std::endl; // 2^0 = 1
    std::cout << pow(2LL, 4LL) << std::endl; // 2^4 = 16
    std::cout << pow(3LL, 6LL) << std::endl; // 3^6 = 729
}