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
    int N;
    std::string S;
    std::cin >> N >> S;
    bool eq = true;
    std::vector<int> R, B;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            B.emplace_back(i + 1);
        } else {
            R.emplace_back(i + 1);
        }
    }
    if (B.size() == N || R.size() == N) {
        for (int i = 1; i <= N - 1; i++) {
            std::cout << i << ' ' << i + 1 << '\n';
        }
        std::cout << 1 << ' ' << N << '\n';
        return;
    }
    int r1 = R.back(); R.pop_back();
    for (int i = 0; i < B.size(); i++) {
        std::cout << r1 << ' ' << B[i] << '\n';
    }
    int b1 = B.back(); B.pop_back();
    for (int i = 0; i < R.size(); i++) {
        std::cout << b1 << ' ' << R[i] << '\n';
    }
    if (!R.empty()) {
        int r2 = R.back();
        if (!B.empty()) {
            std::cout << r2 << ' ' << B.back() << '\n';
        } else {
            std::cout << r2 << ' ' << r1 << '\n';
        }
    } else {
        int b2 = B.back();
        if (!R.empty()) {
            std::cout << b2 << ' ' << R.back() << '\n';
        } else {
            std::cout << b2 << ' ' << b1 << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}