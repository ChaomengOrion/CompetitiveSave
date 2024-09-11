#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> points0(n+1, 0);
    std::vector<int> points1(n+1, 0);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        if (y) points1[x] = 1;
        else points0[x] = 1;
    }

    i64 ans = 0;
    for (int x = 0; x < n; x++) {
        if (!points1[x]) continue;
        if (x > 0 && x < n && points0[x-1] && points0[x+1]) ans++;
    }

    for (int x = 0; x < n; x++) {
        if (!points0[x]) continue;
        if (x > 0 && x < n && points1[x-1] && points1[x+1]) ans++;
        if (points1[x]) {
            ans += n - 2;
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