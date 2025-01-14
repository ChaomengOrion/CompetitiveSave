#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

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

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}