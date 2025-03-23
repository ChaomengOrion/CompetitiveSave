#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

const int MOD = 1e9 + 7;

void solve() {
    i64 N;
    std::cin >> N;

    if (N < 9) {
        std::cout << N << '\n';
        return;
    }

    if (N % 2 == 0) {
        std::cout << N / 2 % MOD << '\n';
        return;
    }

    if (N > 27) {
        std::cout << ((N - 11) / 2 + 1) % MOD << '\n';
    } else {
        int ans;
        switch (N) {
            case 11:
                ans = 4; break;
            case 13:
                ans = 5; break;
            case 15:
                ans = 6; break;
            case 17:
                ans = 8; break;
            case 19:
            case 21:
            case 23:
            case 25:
            case 27:
                ans = 9; break;
        }
        std::cout << ans << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}