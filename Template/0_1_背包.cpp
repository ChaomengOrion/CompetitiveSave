#include <bits/stdc++.h>

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> items(N + 1); // Wi Di
    for (int i = 1; i <= N; i++) {
        std::cin >> items[i].first >> items[i].second;
    }
    std::vector<int> dp(M + 1, 0), last(M + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j - items[i].first >= 0)
                dp[j] = std::max(last[j], last[j - items[i].first] + items[i].second);
            else
                dp[j] = last[j];
        }
        std::swap(dp, last);
        std::fill(dp.begin(), dp.end(), 0);
    }

    std::cout << last.back() << std::endl;
}