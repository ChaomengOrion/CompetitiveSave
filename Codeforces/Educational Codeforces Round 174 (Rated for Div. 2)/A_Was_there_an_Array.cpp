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
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 1; i < N - 1; i++) {
        std::cin >> arr[i];
    }
    int last = -1;
    for (int i = 1; i < N - 1; i++) {
        if (arr[i] == 1) {
            if (last != -1 && i - last >= 2 && i - last <= 2) {
                std::cout << "NO" << '\n';
                return;
            }
            last = i;
        }
    }
    std::cout << "YES" << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}