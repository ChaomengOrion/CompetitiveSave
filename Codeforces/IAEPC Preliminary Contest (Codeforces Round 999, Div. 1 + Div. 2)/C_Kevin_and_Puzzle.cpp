#include <bits/stdc++.h>
using i64 = long long;

const i64 MOD = 998244353;

void solve() {
    int N;
    std::cin >> N;
    std::vector<i64> arr(N);
    for (auto& x : arr) std::cin >> x;

    //* 0诚实 1撒谎 
    std::vector<i64> dp0(N, 0), dp1(N, 0); // 位置i方案数
    std::vector<i64> hn0(N, 0), hn1(N, 0); // 位置i最多诚实的人数
    std::vector<i64> ly0(N, 0), ly1(N, 0); // 位置i最多说谎的人数
    if (arr[0] == 0) {
        dp0[0] = dp1[0] = 1;
        hn0[0] = 1;
        hn1[0] = 0;
        ly0[0] = 0;
        ly1[0] = 1;
    } else {
        dp0[0] = 0;
        dp1[0] = 1;
        hn0[0] = 0;
        hn1[0] = 0;
        ly0[0] = 0;
        ly1[0] = 1;
    }

    for (int i = 1; i < N; i++) {
        if (dp0[i - 1] > 0) {
            dp1[i] = dp0[i - 1];
            dp1[i] %= MOD;
            hn1[i] = hn0[i - 1];
            ly1[i] = ly0[i - 1] + 1;
        }

        // i - hn1[i - 1] 至少说了谎的人数
        if (i - hn1[i - 1] <= arr[i] && arr[i] <= ly1[i - 1] && dp1[i - 1] > 0) {
            dp0[i] += dp1[i - 1];
            dp0[i] %= MOD;
            hn0[i] = std::max(hn0[i],  hn1[i - 1] + 1);
            ly0[i] = std::max(ly0[i], ly1[i - 1]);
        }

        if (arr[i] == arr[i - 1] && dp0[i - 1] > 0) {
            if (i - hn0[i - 1] <= arr[i] && arr[i] <= ly0[i - 1]) {
                dp0[i] += dp0[i - 1];
                dp0[i] %= MOD;
                hn0[i] = std::max(hn0[i],  hn0[i - 1] + 1);
                ly0[i] = std::max(ly0[i], ly0[i - 1]);
            }
        }
    }

    i64 result = (dp0.back() + dp1.back()) % MOD;
    std::cout << result << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}