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

void solve() {
    int N, K;
    std::cin >> N >> K;
    if (K % 2 == 1) {
        for (int i = 1; i <= N - 1; i++) {
            std::cout << N << ' ';
        }
        std::cout << N - 1 << '\n';
    } else {
        for (int i = 1; i <= N - 2; i++) {
            std::cout << N - 1 << ' ';
        }
        std::cout << N << ' ';
        std::cout << N - 1 << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}