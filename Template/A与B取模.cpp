#include <bits/stdc++.h>

using i64 = long long;

i64 add(i64 a, i64 b, i64 p) {
    return (a % p + b % p) % p;
}

i64 sub(i64 a, i64 b, i64 p) {
    return (a % p - b % p) % p;
}

i64 mul(i64 a, i64 b, i64 p) { // a > p
    a %= p;
    b %= p;
    i64 ans = 0;
    while (b > 0) {
        if (b & 1) {
            ans += a;
            ans %= p;
        }
        a <<= 1;
        a %= p;
        b >>= 1;
    }
    return ans;
}

int main() {
    i64 a = 0x7877665544332211;
    i64 b = 0x7988776655443322;
    i64 p = 1E9 + 7;
    std::cout << sub(a, b, p) << std::endl;
}