#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const int MOD = 1E9 + 7;

int binpow(int a, int b)
{
    if (b == 0) return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return 1LL * res * res % MOD * a % MOD;
    else
        return 1LL * res * res % MOD;
}

void solve()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int temp;
        std::cin >> temp;
    }
    for (int i = 0; i < t; i++) {
        int k;
        std::cin >> k;
        std::cout << binpow(2, k) << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}