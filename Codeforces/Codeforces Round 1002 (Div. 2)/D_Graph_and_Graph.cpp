#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    bool visit = false;
    int dis = INT_MAX;
};

void solve() {
    int N, S1, S2;
    int M1, M2;
    std::cin >> N >> S1 >> S2 >> M1;
    std::vector<std::set<int>> graph1(N + 1), graph2(N + 1);
    std::vector<bool> good(N + 1, false);
    for (int i = 0; i < M1; i++) {
        int u, v;
        std::cin >> u >> v;
        graph1[u].emplace(v);
        graph1[v].emplace(u);
    }
    std::cin >> M2;
    for (int i = 0; i < M2; i++) {
        int u, v;
        std::cin >> u >> v;
        if (graph1[u].contains(v)) {
            good[u] = good[v] = true;
        }
        graph2[u].emplace(v);
        graph2[v].emplace(u);
    }

    std::vector graph(N + 1, std::vector<node>(N + 1));
    // <dis, id>
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> Q;

    graph[S1][S2].dis = 0; Q.emplace(0, S1, S2); //! 记得
    while(!Q.empty()) {
        auto [dis, x1, x2] = Q.top(); // 取出最近的
        Q.pop();
        if (graph[x1][x2].visit) continue; //? 可改成cur.dis != dis
        graph[x1][x2].visit = true;

        if (x1 == x2 && good[x1]) {
            std::cout << dis << '\n';
            return;
        }

        for (int s1 : graph1[x1]) {
            for (int s2 : graph2[x2]) {
                if (graph[s1][s2].visit) continue;
                int cost  = abs(s1 - s2);
                if (graph[s1][s2].dis > graph[x1][x2].dis + cost) {
                    graph[s1][s2].dis = graph[x1][x2].dis + cost;
                    Q.emplace(graph[s1][s2].dis, s1, s2);
                }
            }
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}