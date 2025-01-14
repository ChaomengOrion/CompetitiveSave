#include <bits/stdc++.h>

using i64 = long long;
const i64 MOD = 1E9 + 7;

i64 binpow(i64 a, i64 b, i64 p)
{
    if (b == 0) return 1;
    i64 res = binpow(a, b / 2, p);
    if (b % 2)
        return res * res % p * a % p;
    else
        return res * res % p;
}

i64 C(i64 n, i64 m, i64 p)
{
    if (m > n) return 0;
    i64 a = 1, b = 1;
    for (i64 i = 1; i <= m; i++) {
        a = a * (n + i - m) % p;
        b = b * i % p;
    }
    return a * binpow(b, p - 2, p) % p;
}

i64 Lucas(i64 n, i64 m, i64 p)
{
    i64 ans = 1;
    while (n && m) {
        ans = ans * C(n % p, m % p, p) % p;
        n /= p;
        m /= p;
    }
    return ans;
}

int main()
{
    i64 N, A, B;
    std::cin >> N >> A >> B;
    std::cout << (binpow(2, N, MOD) - Lucas(N, A, MOD) - Lucas(N, B, MOD) - 1) % MOD << std::endl;
}