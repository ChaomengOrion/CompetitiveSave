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
    int dp0, dp1; // 0不插，1插
    int root_dp[2]; // 根为dp0/dp1时候这个点是否被插，0不插，1插，2两个情况都存在
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

    auto pre_dfs = [&](auto&& self, int x, int fa, int depth) -> void {
        tree[x].dp0 = 0, tree[x].dp1 = 1; tree[x].depth = depth;
        for (int son : tree[x].to) {
            if (son == fa) continue;
            self(self, son, x, depth + 1);
            tree[x].dp0 += tree[son].dp1;
            tree[x].dp1 += std::min(tree[son].dp0, tree[son].dp1);
        }
    };

    pre_dfs(pre_dfs, 1, -1, 0);

    auto dfs = [&](auto&& self, int x, int fa, int cur_dp, int root) -> void {
        tree[x].root_dp[root] = cur_dp;
        for (int son : tree[x].to) {
            if (son == fa) continue;
            int newdp;
            if (cur_dp == 0) {
                newdp = 1;
            } else if (cur_dp == 2 || tree[son].dp1 == tree[son].dp0) {
                newdp = 2;
            } else {
                newdp = tree[son].dp1 < tree[son].dp0;
            }
            self(self, son, x, newdp, root);
        }
    };

    dfs(dfs, 1, -1, 0, 0);
    dfs(dfs, 1, -1, 1, 1);

    for (int i = 0; i < N - 1; i++) {
        auto [a, b] = edgs[i];
        if (tree[a].depth > tree[b].depth)
            std::swap(a, b);
        // a深度更小
        int bdp0 = tree[b].dp0, bdp1 = tree[b].dp1;
        int adp = std::min(tree[1].dp0 - (tree[b].root_dp[0] == 2 ? std::max(bdp0, bdp1) : (tree[b].root_dp[0] ? bdp1 : bdp0)), 
                           tree[1].dp1 - (tree[b].root_dp[1] == 2 ? std::max(bdp0, bdp1) : (tree[b].root_dp[1] ? bdp1 : bdp0)));
        //LOG(a, b, adp, bdp0, bdp1);
        std::cout << N - std::min(bdp0, bdp1) - adp << " \n"[i == N - 2];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}