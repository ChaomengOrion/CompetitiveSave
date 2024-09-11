#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

const std::vector<std::pair<int, int>> CTRL = {
    {0, 0},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
};

void solve()
{
    int n, m, Hx, Hy;
    std::cin >> n >> m >> Hx >> Hy;
    std::vector dp(n+1, std::vector<i64>(m+1, -1LL));

    for (int i = 0; i < 9; i++) {
        auto [a, b] = CTRL[i];
        if (Hx + a > n || Hy + b > m || Hx + a < 0 || Hy + b < 0) continue;
        dp[Hx + a][Hy + b] = 0;
    }

    dp[0][0] = 1LL;
    for (int y = 0; y <= m; y++) {
        for (int x = 0; x <= n; x++) {
            if (dp[x][y] == -1LL) {
                dp[x][y] = 0LL;
                if (x > 0) dp[x][y] += dp[x-1][y];
                if (y > 0) dp[x][y] += dp[x][y-1];
            }
        }
    }

    std::cout << dp[n][m] << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}