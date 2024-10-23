#include <bits/stdc++.h>

using i64 = long long;

// 关键是注意到只需要计算到达i处最少跳过的分数
void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> score(N + 1);
    std::vector<int> to(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> score[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> to[i];
    }

    // 到达i处最少跳过的分数
    std::vector<i64> wasted(N + 1, LONG_LONG_MAX);
    
    // dijkstra求最短路
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> pq;

    pq.emplace(0, 1);
    wasted[1] = 0;
    while (!pq.empty()) {
        // c是跳过的分数，i是索引
        auto [c, i] = pq.top();
        pq.pop();
        if (wasted[i] != c) {
            continue; // 该点已经有最小值，跳
        }
        // 向前取点
        if (i > 1) {
            if (wasted[i - 1] > c) {
                wasted[i - 1] = c;
                pq.emplace(c, i - 1); // 只考虑临近点就行，i-n的情况一定在处理i-1时处理过
            }
        }
        // 跳点
        if (to[i] > i) { // 只考虑向后跳，向前必定不最优
            c += score[i];
            if (wasted[to[i]] > c) {
                wasted[to[i]] = c;
                pq.emplace(c, to[i]);
            }
        }
    }

    i64 sum = 0, maxScore = 0;
    for (int i = 1; i <= N; i++) {
        sum += score[i];
        maxScore = std::max(maxScore, sum - wasted[i]);
    }
    std::cout << maxScore << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}