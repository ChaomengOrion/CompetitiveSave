#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    vector<vector<int>> pg(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            pg[i][j] = pg[i - 1][j] + pg[i][j - 1] - pg[i - 1][j - 1] + g[i][j];
        }
    }
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    vector<vector<int>> pv(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            pv[i][j] = pv[i - 1][j] + pv[i][j - 1] - pv[i - 1][j - 1] + v[i][j];
        }
    }
    auto check = [&](int a, int b, int c, int d) -> bool {
        if (pv[b][d] - pv[b][c - 1] - pv[a - 1][d] + pv[a - 1][c - 1] <= s) {
            return true;
        }
        return false;
    };
    auto get = [&](int a, int b, int c, int d) -> int {
        return pg[b][d] - pg[b][c - 1] - pg[a - 1][d] + pg[a - 1][c - 1];
    };
    int res = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            for (int i = 1; i <= m; i++) {
                int p = i;
                int q = m;
                int ans = 0;
                while (p <= q) {
                    int mid = (p + q) >> 1;
                    if (check(l, r, i, mid)) {
                        ans = max(ans, mid);
                        p = mid + 1;
                    } else {
                        q = mid - 1;
                    }
                }
                if (ans >= i) {
                    res = max(res, get(l, r, i, ans));
                }
            }
        }
    }
    cout << res;
    return 0;
}