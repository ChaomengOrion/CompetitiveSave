#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

void solve() {
    int N, K;
    std::cin >> N >> K;
    int limit = 1 << N;
    std::vector dp(N + 1, std::vector(K + 1, std::vector<i64>(limit)));
    dp[0][0][0] = 1;
    for (int row = 0; row < N; row++) {
        for (int k = 0; k <= K; k++) {
            for (int st = 0; st < limit; st++) { // 枚举原状态
                if (dp[row][k][st] == 0) continue; // 跳过非法状态
                for (int nst = 0; nst < limit; nst++) { // 枚举新状态
                    if ((nst << 1) & nst) continue; // 新的一行不能相邻
                    if (nst & ((st << 1) | st | (st >> 1))) continue; // 与原来的一行也不能相邻
                    int cnt = std::popcount<unsigned int>(nst); // 这个状态新增了多少个国王
                    if (k + cnt > K) continue;
                    dp[row + 1][k + cnt][nst] += dp[row][k][st]; // 下一行这个状态加上原来的方案数
                }
            }
        }
    }
    std::cout << std::accumulate(dp[N][K].begin(), dp[N][K].end(), 0LL) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}