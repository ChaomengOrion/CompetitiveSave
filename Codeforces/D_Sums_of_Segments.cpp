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
    std::vector<i64> pre1(N + 1), pre2(N + 1);
    for (int i = 1; i <= N; i++) {
        pre1[i] = pre1[i - 1] + arr[i - 1];
        pre2[i] = pre2[i - 1] + i * arr[i - 1];
    }
    auto sum = [&](int k, int end) -> i64 {
        return (end + 1) * (pre1[end] - pre1[k - 1]) - (pre2[end] - pre2[k - 1]);
    };

    std::vector<i64> rangePre(N + 1);
    for (int i = 1; i <= N; i++) {
        rangePre[i] = rangePre[i - 1] + sum(i, N);
    }

    std::vector<i64> startPos(N + 1);
    startPos[1] = 1;
    for (int i = 1; i <= N - 1; i++) {
        startPos[i + 1] = startPos[i] + (N - i + 1);
    }

    auto query = [&](int p) -> i64 {
        if (p == 0) return 0;
        int start = prev(std::upper_bound(startPos.begin(), startPos.end(), p)) - startPos.begin();
        return rangePre[start - 1] + sum(start, p - startPos[start] + start);
    };

    int Q;
    std::cin >> Q;
    while (Q--) {
        int l, r;
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