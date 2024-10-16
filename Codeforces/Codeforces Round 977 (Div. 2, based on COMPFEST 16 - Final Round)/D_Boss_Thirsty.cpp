#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(vec, size)                       \
    std::cerr << #vec << " = " << '[';        \
    for (int i = 0; i < size; i++) {          \
        std::cerr << vec[i];                  \
        if (i != size - 1) std::cerr << ", "; \
    }                                         \
    std::cerr << ']' << std::endl;
using namespace std;


void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector map(n, std::vector<i64>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
        }
    }
    vector<vector<i64>> prefix(n);

    for (int i = 0; i < n; ++i) {
        vector<i64> pre(m + 1, 0);
        for (int j = 0; j < m; ++j) {
            pre[j + 1] = map[i][j] + pre[j];
        }
        prefix[i] = pre;
    }

    // 第 i-1 天和第 i 天的最大利润
    vector<vector<i64>> dp_prev(m, vector<i64>(m, -1e9));
    vector<vector<i64>> dp(m, vector<i64>(m, -1e9));

    // day 1
    for (int l = 0; l < m; ++l) {
        for (int r = l; r < m; ++r) {
            dp_prev[l][r] = prefix[0][r + 1] - prefix[0][l];
        }
    }

    // 从第 2 天开始
    for (int day = 1; day < n; ++day) {
        for (int l = 0; l < m; ++l) {
            for (int r = l; r < m; ++r) {
                dp[l][r] = -1e9;
            }
        }

        // 转移状态
        for (int l1 = 0; l1 < m; ++l1) {
            for (int r1 = l1; r1 < m; ++r1) { // 遍历前一天的左右边界 [l1, r1]
                for (int l2 = 0; l2 < m; ++l2) {
                    for (int r2 = l2; r2 < m; ++r2) { // 遍历当天的左右边界 [l2, r2]
                        bool has_inter = (r1 >= l2 && r2 >= l1); // 是否有交集
                        bool has_diff = l2 < l1 || r2 > r1; // 是否有差异

                        if (has_inter && has_diff) {
                            dp[l2][r2] =
                                max(dp[l2][r2],
                                    dp_prev[l1][r1] + (prefix[day][r2 + 1] - prefix[day][l2]));
                        }
                    }
                }
            }
        }

        dp_prev = dp;
    }

    // 最后一天
    i64 result = -1e9;
    for (int l = 0; l < m; ++l) {
        for (int r = l; r < m; ++r) {
            result = max(result, dp[l][r]);
        }
    }

    std::cout << result << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}