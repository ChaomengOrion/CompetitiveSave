#include <bits/stdc++.h>
// #define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int T, M;
    std::cin >> T >> M; // T: time, M: herbs count
    std::vector<int> herbTimes(M), herbValues(M);
    for (int i = 0; i < M; i++)
        std::cin >> herbTimes[i] >> herbValues[i];
    // dp[i][j] = max(dp[i−1][j], dp[i−1][j−w[i]]+v[i]) // j >= w[i]
    std::vector dp(M + 1, std::vector<int>(T + 1, 0));
    // dp[i][j] = max value of first i herbs with time j
    for (int i = 1; i <= M; i++) {
        for (int t = 0; t <= T; t++) {
            if (t < herbTimes[i - 1])
                dp[i][t] = dp[i - 1][t];
            else
                dp[i][t] = std::max(dp[i - 1][t], dp[i - 1][t - herbTimes[i - 1]] + herbValues[i - 1]);
        }
    }
    std::cout << dp[M][T] << std::endl;
    
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}