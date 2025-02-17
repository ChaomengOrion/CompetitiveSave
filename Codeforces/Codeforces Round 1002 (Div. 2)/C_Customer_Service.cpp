#include <bits/stdc++.h>

using i64 = long long;

int maxRows(std::vector<std::vector<bool>>& grid) {
    if (grid.empty()) return 0;
    const int n = grid.size();
    
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        const auto& row = grid[n - 1 - i];
        for (int j = 0; j < n; ++j) {
            if (row[j]) graph[i].push_back(j);
        }
    }

    std::vector<int> col_match(n, -1);
    int ans = 0;
    
    auto dfs = [&](auto&& self, int u, auto& vis) -> bool {
        for (int v : graph[u]) {
            if (!vis[v]) {
                vis[v] = true;
                if (col_match[v] == -1 || self(self, col_match[v], vis)) {
                    col_match[v] = u;
                    return true;
                }
            }
        }
        return false;
    };

    for (int u = 0; u < n; ++u) {
        std::vector<bool> vis(n, false);
        if (dfs(dfs, u, vis)) ++ans;
    }
    return ans;
}

void solve() {
    int N;
    std::cin >> N;
    std::vector map(N, std::vector<i64>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[j][i];
        }
    }
    std::vector pre(N, std::vector<i64>(N));
    std::vector ok(N, std::vector<bool>(N));
    for (int i = 0; i < N; i++) {
        pre[N - 1][i] = map[N - 1][i];
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            pre[i][j] = pre[i + 1][j] + map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ok[N - 1 - i][j] = pre[N - 1 - i][j] == i + 1;
        }
    }
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << ok[i][j] << ' ';
            
        }
        std::cout << std::endl;
    }*/
    std::cout << std::min(N - 1, maxRows(ok)) + 1 << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}