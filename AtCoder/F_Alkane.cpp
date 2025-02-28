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
    int dp = 0;
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<node> graph(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].to.emplace_back(v);
        graph[v].to.emplace_back(u);
    }
    int ans = 0;
    // 在连通块内扩展烷烃
    auto dfs = [&](auto&& self, int x, int fa) -> void {
        graph[x].dp = 1;
        LOG(x);
        std::vector<int> seq;
        for (int son : graph[x].to) {
            if (son == fa) continue;
            self(self, son, x);
            seq.emplace_back(graph[son].dp);
        }
        std::sort(seq.begin(), seq.end(), std::greater());
        if (!seq.empty()) ans = std::max(ans, seq[0] + 1);
        if (seq.size() >= 4) ans = std::max(ans, seq[0] + seq[1] + seq[2] + seq[3] + 1);
        if (seq.size() >= 3) graph[x].dp = std::max(graph[x].dp, seq[0] + seq[1] + seq[2] + 1);
        return;
    };
    dfs(dfs, 1, -1);
    if (ans < 5) ans = -1;
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}