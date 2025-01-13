#include <bits/stdc++.h>

using i64 = long long;

i64 cal(int n);

void solve() {
    static int cnt = 0;
    int N;
    std::cin >> N;
    std::cout << "Case " << ++cnt << ": " << cal(N) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}

i64 cal(int n) {
    i64 L, R, ans = 0;
    for (L = 1; L <= n; L = R + 1) {
        R = n / (n / L);
        ans += (n / L) * (R - L + 1);
    }
    return ans;
}