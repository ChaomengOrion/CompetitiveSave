#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int x, y, k;
    std::cin >> x >> y >> k;
    int ans = 0;
    if (x == y) {
        ans = x / k + y / k;
        if (x % k > 0) ans++;
        if (y % k > 0) ans++;
    } else if (y > x) {
        int now = x / k;
        ans += 2 * now;
        if (x % k > 0) {
            ans++;
            ans += ((y-now*k) / k)*2-1;
            if ((y-now*k) % k > 0) ans+=2;
        } else {
            ans += ((y-now*k) / k)*2;
            if ((y-now*k) % k > 0) ans+=2;
        }
    } else {
        int now = y / k;
        ans += 2 * now;
        if (y % k > 0) {
            ans++;
            ans += ((x-now*k) / k) * 2 - 2;
            if ((x-now*k) % k > 0) ans+=2;
        } else {
            ans += ((x-now*k) / k) * 2 - 1;
            if ((x-now*k) % k > 0) ans+=2;
        }
    }
    std::cout << ans << std::endl;
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