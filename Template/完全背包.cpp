#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int T, M;
    std::cin >> T >> M; // T: max time cost, M: herbs count
    std::vector<int> herbTimes(M), herbValues(M);
    for (int i = 0; i < M; i++)
        std::cin >> herbTimes[i] >> herbValues[i];
    // dp[i][j] = max(dp[i−1][j], dp[i][j−w[i]]+v[i]) // j >= w[i]
    std::vector dp(std::vector<i64>(T + 1, 0));
    // dp[i][j] = max value of first i herbs with time j
    for (int i = 1; i <= M; i++) {
        for (int t = 0; t <= T; t++) {
            if (t < herbTimes[i - 1])
                dp[t] = dp[t];
            else
                dp[t] = std::max(dp[t], dp[t - herbTimes[i - 1]] + herbValues[i - 1]);
        }
    }
    std::cout << dp.back() << std::endl;
    
}