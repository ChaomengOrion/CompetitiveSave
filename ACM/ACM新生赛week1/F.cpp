#include <bits/stdc++.h>

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;
const int MOD = 1E9 + 7;

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

i64 mod(i64 a, i64 b) { // a / b % mod
    //LOG(a << '/' << b)
    return a * binpow(b, MOD - 2) % MOD;
}

void solve() {
    i64 N;
    std::cin >> N;
    std::vector<i64> pre(N + 1);
    std::vector<i64> pre2(N + 1);
    for (int i = 1; i <= N; i++) {
        i64 temp;
        std::cin >> temp;
        temp %= MOD;
        pre[i] = (temp + pre[i - 1] % MOD) % MOD;
        pre2[i] = (1LL * temp * i % MOD + pre2[i - 1] % MOD) % MOD; 
    }
    i64 mul = 1;
    std::vector<i64> diff(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> diff[i];
        mul *= diff[i] % MOD;
        mul %= MOD;
    }

    auto query = [&](i64 i, i64 r) -> i64 {
        i64 a = r * (pre[i + r - 1] - pre[i - r]);
        i64 b = i * ((pre[i + r - 1] - pre[i]) - (pre[i - 1] - pre[i - r]));
        i64 c = (pre2[i + r - 1] - pre2[i]) - (pre2[i - 1] - pre2[i - r]);
        return (a + b - c + MOD) % MOD;
    };

    i64 a = 0;
    for (int i = 1; i <= N; i++) {
        a += query(i, diff[i]) * mod(mul , diff[i]) % MOD;
        a %= MOD;
    }

    std::cout << mod(a % MOD, N % MOD * mul % MOD) << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}