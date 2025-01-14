#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

//TODO
void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector dp(N + 1, std::vector<int>(N + 1));
    std::vector<int> head(N + 1, -1), next(N + 1), w(N + 1);

    for (int i = 1; i <= N; i++) {
        int a;
        std::cin >> a >> w[i];
        next[i] = head[a];
        head[a] = i;
    }
    for (int i = 1; i <= N; i++) dp[i][0] = w[i];
    dp[0][0] = 0;
    auto dfs = [&](auto&& self, int x) {
        if (head[x] == -1) return 0;
        int sum = 0;
        for (int i = head[x]; i != -1; i = next[i]) {
            int t = self(self, i);
            sum += t + 1;
            for (int j = sum; j >= 0; j--) { //! 注意，一定要是降序
                for (int k = 0; k <= t; k++)
                    if (j - k - 1 >= 0) dp[x][j] = std::max(dp[x][j], dp[x][j - k - 1] + dp[i][k]);
            }
        }
        return sum;
    };
    dfs(dfs, 0);
    std::cout << dp[0][M] << std::endl;
    return;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}