#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    i64 X, M;
    std::cin >> X >> M;
    i64 L = 1;
    while (L <= X) {
        L <<= 1;
    }
    L = std::min(L, M);
    i64 cnt = 0;
    for (int y = 1; y <= L; y++) {
        i64 d = X ^ y;
        if (d != 0 && (y % d == 0 || X % d == 0)) cnt++;
    }
    std::cout << cnt << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}