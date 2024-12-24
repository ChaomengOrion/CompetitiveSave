#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 N, M, K;
    std::cin >> N >> M >> K;

    // 输入
    std::vector grid(N + 1, std::vector<int>(M + 1, INT_MAX));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<i64> last(M + 1, LLONG_MAX - INT_MAX);
    std::vector<i64> next(M + 1, LLONG_MAX - INT_MAX);
    last[1] = 0;

    for (int i = 1; i <= N; ++i) {
        std::vector<int> copy(2 * M + 1);
        for (int j = 1; j <= M; j++) {
            copy[j] = grid[i][j];
            copy[j + M] = grid[i][j];
        }
        i64 cost = 0;
        int moved = 0;
        while (moved < M) {
            std::vector<i64> temp(M + 1, LLONG_MAX - INT_MAX);
            for (int j = 1; j <= M; j++) {
                temp[j] = std::min(last[j], temp[j - 1]) + copy[j + moved];
                next[j] = std::min(next[j], temp[j] + cost);
            }
            moved++;
            cost += K;
        }
        std::swap(last, next);
        std::fill(next.begin(), next.end(), LLONG_MAX - INT_MAX);
    }

    // 输出最小路径的代价
    std::cout << last.back() << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}