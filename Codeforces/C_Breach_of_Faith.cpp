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
    std::vector<i64> arr(N * 2);
    for (int i = 0; i < N * 2; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    i64 L = arr.back(); arr.pop_back();
    std::vector<int> l;
    while (l.size() < arr.size()) {
        l.emplace_back(arr.back());
        arr.pop_back();
    }
    i64 x = std::accumulate(l.begin(), l.end(), L) - std::accumulate(arr.begin(), arr.end(), 0LL);
    std::cout << L << ' ' << x << ' ' << l.back() << ' ';
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ' << l[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}