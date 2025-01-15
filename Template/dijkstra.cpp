#include <bits/stdc++.h>

struct node {
    std::vector<std::pair<int, int>> to;
    bool visit = false;
    int dis = INT_MAX;
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

    // <dis, id>
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> Q;
    graph[S].dis = 0; Q.emplace(0, S); //! 记得
    int cnt = 0;
    while(!Q.empty() && cnt < N) {
        auto [dis, x] = Q.top(); // 取出最近的
        Q.pop();
        if (graph[x].visit) continue; //? 可改成cur.dis != dis
        graph[x].visit = true;
        cnt++;
        for (auto [son, cost] : graph[x].to) {
            if (graph[son].visit) continue; //? 可省略，下一个if也会筛掉，不过最小生成树时候不能删
            if (graph[x].dis + cost < graph[son].dis) { // 松弛边
                graph[son].dis = graph[x].dis + cost;
                Q.emplace(graph[x].dis + cost, son);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << graph[i].dis << ' ';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}