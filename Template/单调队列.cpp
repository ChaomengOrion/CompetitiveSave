#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

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
        dp[i] = dp[dq.front()] + cost[i];
        while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}