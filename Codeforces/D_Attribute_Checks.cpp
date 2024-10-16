#include <bits/stdc++.h>

void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> records(N);
    for (int i = 0; i < N; i++) {
        std::cin >> records[i];
    }
    std::vector dp = std::vector<int>(M + 1, 0); // dp[s] 给S个给力量，过的最多检查点
    int points = records[0] == 0; // 第一个如果不是给点数的就不用考虑了
    bool checked = false; // 用来把n个连续的0的复杂度从O(n^2)降到O(n)
    std::vector<int> CNT_S(M + 1, 0), CNT_I(M + 1, 0);
    for (int i = 1; i < N; i++) {
        if (records[i] == 0) {
            if (checked) {
                // 结算
                for (int i = 1; i <= points; i++) {
                    CNT_I[i] += CNT_I[i - 1];
                    CNT_S[i] += CNT_S[i - 1];
                } // 前缀和
                for (int s = 0; s <= points; s++) {
                    dp[s] += CNT_I[points - s] - CNT_I[0];
                    dp[s] += CNT_S[s] - CNT_S[0];
                }
                points++;
                // 扩散dp状态
                for (int s = points; s > 0; s--) { // 倒序防止覆盖状态
                    dp[s] = std::max(dp[s], dp[s - 1]);
                    // dp[s] -> 多的空一个给智力，dp[s - 1] -> 多的空一个给力量
                }
                std::fill(CNT_I.begin(), CNT_I.end(), 0);
                std::fill(CNT_S.begin(), CNT_S.end(), 0);
            } else {
                points++;
            }
        } else if (records[i] > 0) { // 智力检查
            checked = true;
            CNT_I[records[i]]++;
        } else { // 力量检查
            checked = true;
            CNT_S[-records[i]]++;
        }
    }
    if (records.back() != 0) { // 额外补一次结算
        for (int i = 1; i <= points; i++) {
            CNT_I[i] += CNT_I[i - 1];
            CNT_S[i] += CNT_S[i - 1];
        } // 前缀和
        for (int s = 0; s <= points; s++) {
            dp[s] += CNT_I[points - s] - CNT_I[0];
            dp[s] += CNT_S[s] - CNT_S[0];
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}