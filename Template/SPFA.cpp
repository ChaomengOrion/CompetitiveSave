#include <bits/stdc++.h>

struct node {
    std::vector<std::pair<int, int>> to;
    int dis = INT_MAX;
    bool inQueue = false; // 是否已经在spfa队列中
    int cnt = 0; // 最后一次访问到该节点的spfa的轮数
};

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<node> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        if (c >= 0) {
            graph[u].to.emplace_back(v, c);
            graph[v].to.emplace_back(u, c);
        } else {
            graph[u].to.emplace_back(v, c);
        }
    }

    //* SPFA
    graph[1].cnt = 0, graph[1].dis = 0, graph[1].inQueue = true;
    std::queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        graph[x].inQueue = false;
        for (auto [son, cost] : graph[x].to) {
            if (graph[x].dis + cost < graph[son].dis) { // 尝试松弛边，松弛成功就加入下一轮
                graph[son].dis = graph[x].dis + cost;
                graph[son].cnt = graph[x].cnt + 1;
                if (graph[son].cnt >= N) {
                    std::cout << "YES" << std::endl; // 存在负环
                    return;
                }
                if (!graph[son].inQueue) {
                    Q.emplace(son);
                    graph[son].inQueue = true;
                }
            }
        }
    }

    std::cout << "NO" << std::endl;
}