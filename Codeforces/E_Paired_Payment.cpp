#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    std::vector<std::pair<int, int>> to;
    int cost = -1;
};

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<node> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        graph[u].to.push_back({v, c});
        graph[v].to.push_back({u, c});
    }

    std::vector<std::array<int, 3>> wait; // p id pre_cost
    bool flag = true;

    wait.push_back({0, 1, 0});

    while (!wait.empty()) {
        std::vector<std::array<int, 3>> next;
        for (auto [p, id, pc] : wait) {
            for (auto [nxt, c] : graph[id].to) {
                if (nxt != p) {
                    next.push_back({id, nxt, pc + c});
                }
            }
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}