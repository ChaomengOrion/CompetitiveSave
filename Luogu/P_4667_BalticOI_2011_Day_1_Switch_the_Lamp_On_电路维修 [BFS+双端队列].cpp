#include <bits/stdc++.h>

struct node {
    std::vector<std::pair<int, bool>> to;
    bool finished = false;
    int minDis = INT_MAX;
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

    std::deque<int> pending;
    graph[0].minDis = 0;
    pending.emplace_back(0);
    int end = (H + 1) * (W + 1) - 1;
    while(!pending.empty()) {
        if (pending.front() == end) break;
        node& cur = graph[pending.front()];
        pending.pop_front();
        if (cur.finished) continue;
        cur.finished = true;
        for (auto [id, cost] : cur.to) {
            if (graph[id].finished) continue;
            if (graph[id].minDis > cur.minDis + cost) {
                graph[id].minDis = cost + cur.minDis;
                cost == 0 ? pending.emplace_front(id) : pending.emplace_back(id);
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