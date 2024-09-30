#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    std::vector<int> to;
    int cost = -1;
};

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<node> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].to.push_back(v);
        graph[v].to.push_back(u);
    }
    auto bfs = [&](auto&& bfs, int id) {

    };
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}