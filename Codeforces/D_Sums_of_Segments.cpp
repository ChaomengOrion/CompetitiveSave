#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<short> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> pre1(N + 1);
    std::vector<i64> pre2(N + 1);
    for (int i = 1; i <= N; i++) {
        pre1[i] = pre1[i - 1] + arr[i - 1];
        pre2[i] = pre2[i - 1] + 1LL * i * arr[i - 1];
    }
    auto sum = [&](int k, int end) -> i64 {
        return 1LL * (end + 1) * (pre1[end] - pre1[k - 1]) - (pre2[end] - pre2[k - 1]);
    };

    std::vector<i64> rangePre(N + 1);
    for (int i = 1; i <= N; i++) {
        rangePre[i] = rangePre[i - 1] + sum(i, N);
    }

    auto query = [&](i64 p) -> i64 {
        if (p == 0) return 0;
        int start = (int)(N + 1.5 - sqrtl((N + 1.5) * (N + 1.5) - 2 * (N + p)));
        i64 startPos = (i64)(-1LL * start * start / 2.0 + (N + 1.5) * start - N);
        return rangePre[start - 1] + sum(start, (int)(p - startPos + start));
    };

    int Q;
    std::cin >> Q; 
    while (Q--) {
        i64 l, r;
        std::cin >> l >> r;
        std::cout << query(r) - query(l - 1) << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}