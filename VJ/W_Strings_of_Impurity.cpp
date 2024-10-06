#include <bits/stdc++.h>
using i64 = long long;

void solve()
{
    std::string s, t;
    std::cin >> s >> t;
    i64 n = s.size(), m = t.size();
    std::vector v(26, std::vector<i64>());
    i64 ans = 0, pre = 0;
    for (int i = 0; i < n; i++) v[s[i] - 'a'].push_back(i + 1);
    for (int i = 0; i < 26; i++) v[i].push_back(n + 1);
    for (int i = 0; i < m; i++) {
        if (v[t[i] - 'a'].size() == 1) {
            std::cout << -1 << std::endl;
            return;
        }
        auto now = lower_bound(v[t[i] - 'a'].begin(), v[t[i] - 'a'].end(), pre);
        if (*now == pre) now++;
        i64 cur = *now;
        if (cur == n + 1)
            ans += n, pre = v[t[i] - 'a'][0];
        else
            pre = cur;
    }
    std::cout << ans + pre << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}