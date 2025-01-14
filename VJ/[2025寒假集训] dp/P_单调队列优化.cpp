#include <bits/stdc++.h>

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> cost(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cost[i];
    }

    std::vector<int> dp(N);
    std::deque<int> dq;
    dq.emplace_back(0);
    dp[0] = cost[0];
    for (int i = 1; i < N; i++) {
        while (!dq.empty() && dq.front() < i - K) dq.pop_front(); // [i - K, i - 1]
        dp[i] = i >= K ? dp[dq.front()] + cost[i] : cost[i];
        while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    std::cout << *std::min_element(K <= dp.size() ? dp.end() - K : dp.begin(), dp.end()) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}