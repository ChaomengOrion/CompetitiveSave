#include <bits/stdc++.h>

void solve()
{
    int N, M, S; // 点 边 出发点
    std::cin >> N >> M >> S;
    std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, len;
        std::cin >> u >> v >> len;
        graph[u].emplace_back(v, len);
        //graph[v].to.emplace_back(u, len);
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    std::vector<int> dis(N + 1, INT_MAX);
    dis[S] = 0;
    pq.emplace(0, S);
    while(!pq.empty()) {
        auto [d, i] = pq.top();
        pq.pop();
        if (d != dis[i]) continue;

        for (auto [nid, cost] : graph[i]) {
            if (dis[nid] > dis[i] + cost) {
                dis[nid] = dis[i] + cost;
                pq.emplace(dis[nid], nid);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << dis[i] << ' ';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}