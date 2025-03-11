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
    int depth;
    int dp[2]; // 0不插，1插
    int rdp[2]; // 以这个点为根的答案
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<node> tree(N + 1);
    std::vector<std::pair<int, int>> edgs(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        edgs[i] = {u, v};
        tree[u].to.emplace_back(v);
        tree[v].to.emplace_back(u);
    }

    // 预处理dp
    auto pre_dfs = [&](auto&& self, int x, int fa, int depth) -> void {
        tree[x].dp[0] = 0;
        tree[x].dp[1] = 1;
        tree[x].depth = depth;
        for (int son : tree[x].to) {
            if (son == fa) continue;
            self(self, son, x, depth + 1);
            tree[x].dp[0] += tree[son].dp[1];
            tree[x].dp[1] += std::min(tree[son].dp[0], tree[son].dp[1]);
        }
    };

    pre_dfs(pre_dfs, 1, -1, 0);

    // 换根dp
    auto dfs = [&](auto&& self, int x, int fa) -> void {
        if (fa == -1) {
            tree[x].rdp[0] = tree[x].dp[0];
            tree[x].rdp[1] = tree[x].dp[1];
        } else {
            tree[x].rdp[0] = tree[x].dp[0] + (tree[fa].rdp[1] - std::min(tree[x].dp[0], tree[x].dp[1]));
            tree[x].rdp[1] = tree[x].dp[1] + std::min(tree[fa].rdp[1] - std::min(tree[x].dp[0], tree[x].dp[1]), tree[fa].rdp[0] - tree[x].dp[1]);
        }
        for (int son : tree[x].to) {
            if (son == fa) continue;
            self(self, son, x);
        }
    };

    dfs(dfs, 1, -1);

    for (int i = 0; i < N - 1; i++) {
        auto [a, b] = edgs[i];
        if (tree[a].depth > tree[b].depth)
            std::swap(a, b);
        // a深度更小
        int bdp0 = tree[b].dp[0], bdp1 = tree[b].dp[1];
        int adp0 = tree[a].rdp[0] - bdp1, adp1 = tree[a].rdp[1] - std::min(bdp0, bdp1);
        //LOG(a, b, adp, bdp0, bdp1);
        std::cout << N - std::min(bdp0, bdp1) - std::min(adp0, adp1) << " \n"[i == N - 2];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}