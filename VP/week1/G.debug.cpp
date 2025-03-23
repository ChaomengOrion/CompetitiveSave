#include <bits/stdc++.h>
#include <vector>
#define CERR std::cerr << "[debug_line:" << __LINE__ << "]: "
using ld = long double;
using ll = long long;
const int MAXN = 1e9;
const int N = 1e5;

using namespace std;

void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // 每个区间的最大值的数量，位置
    auto dfs = [&](auto& dfs, ll l, ll r) {
        if (l + k - 1 > r) return;
        
        vector<vector<ll>> pos(n + 1);
        ll maxi = 0; // 最大值
        for(int i = l; i <= r; i++){
            pos[a[i]].push_back(i);
            maxi = max(maxi, a[i]);
        }

        //最大值的个数
        ll maxcnt = pos[maxi].size();

        if (maxcnt >= k) {
            ans += (pos[maxi][0] - l + 1) * (r - pos[maxi][0 + k - 1] + 1);
            for (int i = 1; i < maxcnt - k + 1; i++) {
                ans += (pos[maxi][i] - pos[maxi][i - 1]) * (r - pos[maxi][i + k - 1] + 1);
            }
        }

        dfs(dfs, l, pos[maxi][0] - 1);
        for(int i = 1; i < maxcnt; i++){
            dfs(dfs, pos[maxi][i - 1] + 1, pos[maxi][i] - 1);
        }
        dfs(dfs, pos[maxi][maxcnt - 1] + 1, r);
    };
    dfs(dfs, 1, n);

    cout << ans << '\n';
}

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}