#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    i64 n, q;
    std::cin >> n >> q;
    std::vector<i64> pre(n+1, 0);
    for (i64 i = 1; i <= n; i++) {
        std::cin >> pre[i];
        pre[i] += pre[i-1];
    }
    i64 sum = pre[n];

    auto cal = [&](i64 th, i64 l, i64 r) -> i64 {
        if (l == r) return pre[(th + l)%n+1]-pre[(th + l)%n];
        l += th;
        r += th;
        if (r > n - 1) r %= n;
        if (l > n - 1) l %= n;
        if (l < r) {
            return pre[r+1] - pre[l];
        } else {
            return pre[n] - pre[l] + pre[r+1];
        }
    };

    while (q--) {
        i64 l, r;
        std::cin >> l >> r;
        l--; r--;
        i64 rth = r / n;
        i64 ri = r % n;
        i64 lth = l / n;
        i64 li = l % n;
        i64 ans;
        if (rth != lth) {
            ans = (rth - lth - 1) * sum + cal(lth, li, n-1) + cal(rth, 0, ri);
        } else {
            ans = cal(lth, li, ri);
        }
        std::cout << ans << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}