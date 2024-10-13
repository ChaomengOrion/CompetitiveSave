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
    int H, W;
    std::cin >> H >> W;
    if ((H + W) % 2 != 0) {
        std::cout << "NO SOLUTION" << std::endl;
        return;
    }

    std::vector<node> graph((H + 1) * (W + 1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            std::cin >> c;
            if (c == '/') {
                // i + 1, j - i, j + 1
                graph[(i + 1) * (W + 1) + j].to.emplace_back(i * (W + 1) + (j + 1), 0);
                graph[i * (W + 1) + (j + 1)].to.emplace_back((i + 1) * (W + 1) + j, 0);
                graph[i * (W + 1) + j].to.emplace_back((i + 1) * (W + 1) + (j + 1), 1);
                graph[(i + 1) * (W + 1) + (j + 1)].to.emplace_back(i * (W + 1) + j, 1);
            } else {
                // i, j - i + 1, j + 1
                graph[i * (W + 1) + j].to.emplace_back((i + 1) * (W + 1) + (j + 1), 0);
                graph[(i + 1) * (W + 1) + (j + 1)].to.emplace_back(i * (W + 1) + j, 0);
                graph[(i + 1) * (W + 1) + j].to.emplace_back(i * (W + 1) + (j + 1), 1);
                graph[i * (W + 1) + (j + 1)].to.emplace_back((i + 1) * (W + 1) + j, 1);
            }
        }
    }

    std::priority_queue<task, std::vector<task>, std::greater<task>> pending;
    graph[0].minDis = 0;
    pending.emplace(0, 0);
    while(!pending.empty()) {
        if (pending.top().id == (H + 1) * (W + 1) - 1) break;
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

    std::cout << graph.back().minDis;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}