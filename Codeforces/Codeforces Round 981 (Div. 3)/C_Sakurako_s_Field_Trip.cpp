#include <bits/stdc++.h>

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int half = N / 2;
    for (int i = 1; i < half; i++) {
        int down = i, up = N - 1 - i;
        int pred = arr[down - 1], preu = arr[up + 1];
        int u = arr[up], d = arr[down];
        int cnt1 = (u == preu) + (d == pred),
            cnt2 = (u == pred) + (d == preu);
        if (cnt2 < cnt1) {
            std::swap(arr[up], arr[down]);
        }
    }

    int sum = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i - 1]) sum++;
    }
    std::cout << sum << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}