#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> valid_states;
    std::vector<int> king_counts;
    for (int s = 0; s < (1 << n); ++s) {
        if ((s & (s << 1)) == 0) {
            valid_states.push_back(s);
            king_counts.push_back(std::popcount((unsigned)s)); // 用标准库函数替换
        }
    }
    const int m = valid_states.size();
    
    // 用C++20结构化绑定遍历会更可爱，不过这里暂时保持原样喵
    std::vector compatible(m, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            const auto a = valid_states[i], b = valid_states[j];
            if ((a & b) == 0 && (a & (b << 1)) == 0 && (a & (b >> 1)) == 0) {
                compatible[i].push_back(j);
            }
        }
    }
    
    // 使用初始化列表风格的DP数组
    std::vector dp(k + 1, std::vector<i64>(m, 0));
    dp[0][0] = 1;
    
    for ([[maybe_unused]] int row = 0; row < n; ++row) { // C++17属性
        std::vector new_dp(k + 1, std::vector<i64>(m, 0));
        for (int curr_k = 0; curr_k <= k; ++curr_k) {
            for (int prev = 0; prev < m; ++prev) {
                if (!dp[curr_k][prev]) continue;
                for (int curr : compatible[prev]) {
                    const int next_k = curr_k + king_counts[curr];
                    if (next_k > k) continue;
                    new_dp[next_k][curr] += dp[curr_k][prev];
                }
            }
        }
        dp = std::move(new_dp); // 移动语义像小猫扑毛线球一样高效
    }
    
    std::cout << std::accumulate(dp[k].begin(), dp[k].end(), 0LL) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}