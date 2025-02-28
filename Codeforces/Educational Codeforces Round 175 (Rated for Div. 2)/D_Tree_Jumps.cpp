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
    std::vector<std::vector<int>> tree(N + 1);
    std::vector<int> dis(N + 1);
    for (int i = 2; i <= N; i++) {
        int fa; std::cin >> fa;
        tree[fa].emplace_back(i);
    }
    std::queue<int> Q;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int son : tree[x]) {
            dis[son] = dis[x] + 1;
            Q.emplace(son);
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}