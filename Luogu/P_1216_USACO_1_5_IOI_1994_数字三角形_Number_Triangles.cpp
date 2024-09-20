#include <bits/stdc++.h>
// zd#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int h;
    std::cin >> h;
    std::vector<std::vector<int>> dp(h);
    for (int i = 0; i < h; i++) {
        dp[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
            std::cin >> dp[i][j];
    }
    for (int i = h - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++)
            dp[i][j] += std::max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
    std::cout << dp[0][0] << std::endl;
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