#include <bits/stdc++.h>

using i64 = long long;
using d64 = double;
using d128 = long double;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    d64 R, rot;
    std::cin >> R >> rot;
    rot = std::min(rot, 2.0 * std::numbers::pi - rot);
    d64 dis = R * rot;
    for (int i = 0; i < N; i++) {
        d64 r;
        std::cin >> r;
        dis = std::min(dis, r * rot + 2.0 * (R - r));
    }

    std::cout << std::fixed << std::setprecision(9) << dis << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}