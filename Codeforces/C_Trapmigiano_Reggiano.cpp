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
    std::vector<int> to;
};

void solve() {
    int N, st, en;
    std::cin >> N >> st >> en;
    std::vector<node> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].to.emplace_back(v);
        graph[v].to.emplace_back(u);
    }
    std::vector<int> ans_en;
    auto dfs_en = [&](auto&& self, int x, int fa) -> void {
        for (int son : graph[x].to) {
            if (son == fa) continue;
            self(self, son, x);
        }
        ans_en.emplace_back(x);
    };
    dfs_en(dfs_en, en, -1);
    for (int i : ans_en) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}