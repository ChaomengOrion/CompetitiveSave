#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1E9 + 7;

int findFirst(int k) {
    if (k == 1) return 1;
    int f1 = 0, f2 = 1;
    int index = 2;
    while (true) {
        int fn = (f1 + f2) % k;
        if (fn == 0) return index;
        f1 = f2;
        f2 = fn;
        index++;
    }
}

void solve()
{
    i64 N; int K;
    std::cin >> N >> K;
    std::cout << N % MOD * findFirst(K) % MOD << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}