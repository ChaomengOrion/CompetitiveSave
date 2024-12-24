#include <bits/stdc++.h>

typedef long long ll;
#define long long int
#define inf 0x3f3f3f3f
#define endl '\n'
#define db(a) cout << #a << " = " << a << endl;
#define cy cout << "YES" << '\n'
#define cn cout << "NO" << '\n'
using namespace std;
typedef pair<int, int> PII;
int T = 1;
const int N = 4e5 + 100;
ll n, k;
ll a[N], b[N], c[N], d[N], g[N];
ll p[2 * N], tp[2 * N];
map<ll, ll> fu;
map<ll, ll> fn;
void solve() {
    fu.clear();
    fn.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        tp[2 * i - 1] = a[i];
        tp[2 * i] = b[i];
    }
    sort(tp + 1, tp + 2 * n + 1);
    ll tt = 0, last = -1;
    for (int i = 1; i <= 2 * n; i++) {
        if (tp[i] != last) {
            p[++tt] = tp[i];
            last = tp[i];
        }
    }
    for (int i = 1; i <= tt; i++) {
        fu[p[i]] = i;
        fn[i] = p[i];
    }
    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; i++) {
        d[fu[a[i]] + 1]++;
        d[fu[b[i]] + 1]--;
    }
    c[0] = 0;
    for (int i = 1; i <= tt; i++) {
        c[i] = c[i - 1] + d[i];
    }
    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; i++) {
        d[1]++;
        d[fu[b[i]] + 1]--;
    }
    g[0] = 0;
    for (int i = 1; i <= tt; i++) {
        g[i] = g[i - 1] + d[i];
    }
    ll ans = 0;
    for (int i = 1; i <= tt; i++) {
        if (c[i] <= k) {

            ans = max(ans, (ll)fn[i] * (ll)g[i]);
            // cout<<fn[i]<<endl;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}