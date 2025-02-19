#include <bits/stdc++.h>

const int MOD = 998244353;

void solve() {
    int N;
    std::cin >> N;
    int one = 0, dp = 0, ans = 0;
    for (int i = 0, x; i < N; i++) {
        std::cin >> x;
        if (x == 1) one++;
        else if (x == 2) dp = (dp * 2 % MOD + one) % MOD;
        else ans = (ans + dp) % MOD;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}