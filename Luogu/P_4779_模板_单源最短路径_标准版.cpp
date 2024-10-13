#include <bits/stdc++.h>

struct node {
    std::vector<std::pair<int, int>> to;
    bool finished = false;
    int minDis = INT_MAX;
};

struct task {
    int id, dis;
    task(int id, int dis) : id(id), dis(dis) {}

    bool operator>(const task& another) const {
        return dis > another.dis;
    }
};

void solve()
{
    int N, M, S; // 点 边 出发点
    std::cin >> N >> M >> S;
    std::vector<node> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, len;
        std::cin >> u >> v >> len;
        graph[u].to.emplace_back(v, len);
        //graph[v].to.emplace_back(u, len);
    }

    std::priority_queue<task, std::vector<task>, std::greater<task>> pending;
    graph[S].minDis = 0;
    pending.emplace(S, 0);
    while(!pending.empty()) {
        node& cur = graph[pending.top().id];
        pending.pop();
        if (cur.finished) continue;
        cur.finished = true;
        for (auto [id, cost] : cur.to) {
            if (graph[id].finished) continue;
            if (graph[id].minDis > cur.minDis + cost) {
                graph[id].minDis = cost + cur.minDis;
                pending.emplace(id, cost + cur.minDis);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << graph[i].minDis << ' ';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}