#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    std::vector<int> to;
    i64 depth_sum;
    int size;
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

    std::vector<char> vis(N + 1, false);
    auto filter = std::views::filter([&](int x) { return !vis[x]; });

    auto dfs1 = [&](auto&& self, int x, int depth) -> void {
        vis[x] = true;
        graph[x].depth_sum = depth;
        graph[x].size = 1;
        for (int son : graph[x].to | filter) {
            self(self, son, depth + 1);
            graph[x].depth_sum += graph[son].depth_sum;
            graph[x].size += graph[son].size;
        }
    };

    dfs1(dfs1, 1, 1);
    
    //* 对于x，它的父亲是y，有f[x]=f[y]-size[x]+(n-size[x])

    i64 ans = graph[1].depth_sum, root = 1;
    std::fill(vis.begin(), vis.end(), false);
    auto dfs2 = [&](auto&& self, int y, int x) -> void {
        vis[x] = true;
        i64 sum = graph[y].depth_sum + N - 2 * graph[x].size;
        graph[x].depth_sum = sum;
        if (sum > ans) {
            ans = sum;
            root = x;
        }
        for (int son : graph[x].to | filter) {
            self(self, x, son);
        }
    };
    
    vis[1] = true;
    for (int son : graph[1].to) {
        dfs2(dfs2, 1, son);
    }

    std::cout << root << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}