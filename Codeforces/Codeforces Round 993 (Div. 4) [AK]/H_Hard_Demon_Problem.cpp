#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector map(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    std::vector pre(N + 1, std::vector<i64>(N + 1));
    std::vector prex(N + 1, std::vector<i64>(N + 1));
    std::vector prey(N + 1, std::vector<i64>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] = map[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]; 
            prex[i][j] = 1LL * map[i - 1][j - 1] * i + prex[i - 1][j] + prex[i][j - 1] - prex[i - 1][j - 1]; 
            prey[i][j] = 1LL * map[i - 1][j - 1] * j + prey[i - 1][j] + prey[i][j - 1] - prey[i - 1][j - 1]; 
        }
    }

    auto query = [](std::vector<std::vector<i64>>& pre, int x1, int y1, int x2, int y2) -> i64 {
        return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    };

    while (Q--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        i64 a = -1LL * x1 * (y2 - y1 + 1) - y1 + 1;
        i64 b = y2 - y1 + 1;
        i64 sum = a * query(pre, x1, y1, x2, y2)
            + b * query(prex, x1, y1, x2, y2)
            + query(prey, x1, y1, x2, y2);
        std::cout << sum << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}