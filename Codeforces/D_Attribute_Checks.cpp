#include <bits/stdc++.h>
namespace Use
{
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::abs;
} // namespace Use
using namespace Use;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ve(n + 10, 0); // 地图
    vector<vector<int>> dp1(m + 10,
                            vector<int>(m + 10, 0)); // 到第i个技能点,点j级智力,i-j级力量，收益
    vector<int> pre1(m + 10, 0); // 智力计数
    vector<int> pre2(m + 10, 0); // 力量计数
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        int val = abs(ve[i]);
        if (ve[i] > 0) pre1[val]++;
        if (ve[i] < 0) pre2[val]++;
    }
    int cnt = 0;
    int ptr = 1;
    while (cnt < m && ptr < n) {

        if (ve[ptr] == 0) {
            cnt++;
            while (ve[ptr] != 0 && ptr < n) {
                ptr++;
                int val = abs(ve[ptr]);
                if (ve[ptr] > 0) pre1[val]--; // 这些点不会再计算
                if (ve[ptr] < 0) pre2[val]--;
            }
            for (int i = 0; i <= cnt; i++) {
                if (i == 0)
                    dp1[cnt][i] = dp1[cnt - 1][i] + pre2[cnt];
                else if (i == cnt)
                    dp1[cnt][i] = dp1[cnt - 1][cnt - 1] + pre1[cnt];
                else
                    dp1[cnt][i] = max(dp1[cnt - 1][i] + pre2[cnt - i],
                                      dp1[cnt - 1][i - 1] + pre1[i]); // 点力量和点智力取最大
            }
        } else {
            ptr++;
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, dp1[m][i]);
    }
    cout << ans << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
