#include <bits/stdc++.h>

using i64 = long long;
using d32 = float;
using d64 = double;
using d128 = long double;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

d64 dis(std::pair<d64, d64>& a, std::pair<d64, d64>& b) {
    return std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve() {
    int N;
    std::cin >> N;
    std::vector<std::pair<d64, d64>> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].first >> points[i].second;
    }
    d64 ans = INFINITY;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = std::min(ans, dis(points[i], points[j]));
        }
    }

    std::cout << std::fixed << std::setprecision(4) << ans;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}