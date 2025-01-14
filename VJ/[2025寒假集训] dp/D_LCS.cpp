#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

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

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}