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

struct node {
    int id;
    int pri;
    int index;

    friend bool operator<(const node& a, const node& b) {
        if (a.pri == b.pri) return a.index < b.index;
        return a.pri < b.pri;
    }
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<node> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i].id;
        arr[i].index = i;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i].pri;
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) {
        std::cout << arr[i].id << " \n"[i == N - 1];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}