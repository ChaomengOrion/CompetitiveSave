#include <bits/stdc++.h>

void solve() {
    std::string S, T;
    std::cin >> S >> T;
    std::vector dp(S.size() + 1, std::vector<int>(T.size() + 1));
    for (int i = 1; i <= S.size(); i++) {
        for (int j = 1; j <= T.size(); j++) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    std::string ans;
    int i = S.size(), j = T.size();
    while (i > 0 && j > 0) {
        if (S[i - 1] == T[j - 1]) {
            ans += S[i - 1];
            i--; j--;
        } else {
            dp[i - 1][j] > dp[i][j - 1] ? i-- : j--;
        }
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << std::endl;
}