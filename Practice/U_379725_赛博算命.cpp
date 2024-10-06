#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int Q, N;
    cin >> Q >> N;
    vector<int> tm(Q);
    for (int i = 0; i < Q; i++) {
        cin >> tm[i];
    }
    int exp = 1 << (int)log2(N), ans = 1;
    if (exp == N) {
        for (int i = 0; i < Q; i++) {
            ans = 1LL * ans * (N - (tm[i] - 1)) % MOD;
        }
    } else {
        int limit = N - exp;
        for (int i = 0; i < Q; i++) {
            if (tm[i] > limit && tm[i] <= exp) {
                ans = 1LL * ans * (N + 1) % MOD;
            } else {
                ans = 1LL * ans * (N - (tm[i] - 1)) % MOD;
            }
        }
    }
    cout << ans << '\n';
}