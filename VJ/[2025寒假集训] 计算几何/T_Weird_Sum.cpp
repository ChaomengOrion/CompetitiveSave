#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector map(N, std::vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    std::map<int, std::pair<std::vector<int>, std::vector<int>>> record;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            record[map[i][j]].first.push_back(i);
            record[map[i][j]].second.push_back(j);
        }
    }
    i64 ans = 0;
    for (auto [k, _] : record) {
        auto [rl, cl] = _;
        std::sort(rl.begin(), rl.end());
        std::sort(cl.begin(), cl.end());
        i64 sum = 0;
        for (int i = 0; i < rl.size(); i++) {
            ans += 1LL * i * rl[i] - sum;
            sum += rl[i];
        }
        sum = 0;
        for (int i = 0; i < cl.size(); i++) {
            ans += 1LL * i * cl[i] - sum;
            sum += cl[i];
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}