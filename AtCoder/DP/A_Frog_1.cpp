#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> H(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> H[i];
    }
    std::vector<int> dp(N + 1);
    dp[1] = 0;
    dp[2] = abs(H[2] - H[1]);
    for (int i = 3; i <= N; i++) {
        dp[i] = std::min(dp[i - 1] + abs(H[i] - H[i - 1]),
                         dp[i - 2] + abs(H[i] - H[i - 2]));
    }
    std::cout << dp[N] << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}