#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    std::vector<std::pair<int, int>> to;
    int cost = -1;
};

struct task {
    int parent, id, pre_cost, from_weight;
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
    graph[1].cost = 0;

    std::vector<task> p1, p2; // p id pre_cost

    bool flag = true;

    std::vector<task>& pending = p1;
    std::vector<task>& nxt = p2;

    pending.push_back({0, 1, 0, 0});

    while (!pending.empty()) {
        flag = !flag;
        nxt.clear();
        nxt.reserve(n);
        for (task t : pending) {
            for (auto [id, weight] : graph[t.id].to) {
                if (!(flag && id == t.parent)) {
                    if (flag) {
                        int cost = t.from_weight + weight;
                        cost *= cost;
                        cost += t.pre_cost;
                        if (graph[id].cost == -1 || graph[id].cost > cost) {
                            graph[id].cost = cost;
                            nxt.push_back({t.id, id, cost, weight});
                        } else continue;
                    } else {
                        nxt.push_back({t.id, id, t.pre_cost, weight});
                    }
                }
            }
        }
        std::swap(pending, nxt);
    }

    for (int i = 1; i <= n; i++) {
        std::cout << graph[i].cost << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}