#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector map(N, std::vector<i64>(M));
    std::string route;
    std::cin >> route;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    std::vector<i64> rowSum(N), colSum(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            rowSum[i] += map[i][j];
            colSum[j] += map[i][j];
        }
    }

    static const i64 target = 0;

    int x = 0, y = 0;
    for (int i = 0; i < route.size(); i++) {
        if (route[i] == 'D') {
            map[x][y] = target - rowSum[x];
            rowSum[x] += map[x][y];
            colSum[y] += map[x][y];
            x++;
        } else {
            map[x][y] = target - colSum[y];
            rowSum[x] += map[x][y];
            colSum[y] += map[x][y];
            y++;
        }
    }

    map[x][y] = target - colSum[y];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}