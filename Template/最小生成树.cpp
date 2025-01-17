#include <bits/stdc++.h>
using i64 = long long;
struct node {
    std::vector<std::pair<int, int>> to;
    int dis = INT_MAX;
    bool visited = false;
};

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<node> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        graph[u].to.emplace_back(v, c);
        graph[v].to.emplace_back(u, c);
    }

    i64 ans = 0;
    // <dis, id>
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> Q;
    graph[1].dis = 0; Q.emplace(0, 1);
    int cnt = 0;
    while (!Q.empty() && cnt < N) {
        auto [dis, x] = Q.top(); // 选连通块旁边最近的边加入
        Q.pop();
        if (graph[x].visited) continue; //? 说明提前算完这个点了
        graph[x].visited = true;
        cnt++;
        ans += dis; // 加上路径和
        for (auto [son, cost] : graph[x].to) {
            if (graph[son].visited) continue;
            if (cost < graph[son].dis) {
                graph[son].dis = cost; // 更新子节点到连通块最小距离
                Q.emplace(cost, son); // 把连通块相邻边加入
            }
        }
    }

    if (cnt < N) {
        std::cout << "orz" << std::endl;
        return;
    }

    std::cout << ans << std::endl;
}