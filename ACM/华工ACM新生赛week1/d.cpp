#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;
const int MOD = 998244353;

i64 binpow(i64 a, i64 b) {
    a %= MOD;
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void out(i64 a, i64 b) { // a / b % mod
    std::cout << a * binpow(b, MOD - 2) % MOD << std::endl;
}

void cal(i64 N, i64 K, bool a0) {
    i64 sgn = (K & 1) ? -1 : 1;
    i64 nk = binpow(N - 1, K);
    i64 a = sgn * (N * a0 - 1) + nk;
    a %= MOD;
    i64 b = nk * N % MOD;
    out(a, b);
}

void solve() {
    i64 n, a1, k1, a2, k2;
    std::cin >> n >> a1 >> k1 >> a2 >> k2;
    cal(n, abs(a2 - a1), k2 == k1);
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}