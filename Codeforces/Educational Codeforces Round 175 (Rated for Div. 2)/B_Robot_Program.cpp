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
    i64 N, X, K;
    std::string S;
    std::cin >> N >> X >> K >> S;
    i64 t1 = -1, t2 = -1;
    i64 pos = X;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') X--;
        else X++;
        if (X == 0) {
            t1 = i + 1;
            break;
        }
    }
    if (t1 == -1) {
        std::cout << 0 << '\n';
        return;
    }
    pos = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') X--;
        else X++;
        if (X == 0) {
            t2 = i + 1;
            break;
        }
    }
    if (t2 == -1) {
        std::cout << (t1 <= K ? 1 : 0) << '\n';
        return;
    }
    if (t1 <= K) {
        K -= t1;
        std::cout << (K / t2) + 1 << '\n';
    } else {
        std::cout << 0 << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}