#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    std::set<i64> lose;
    i64 last = 3;
    lose.emplace(last);
    while (last < 1e18) {
        last = 2LL * last - 1;
        lose.emplace(last);
    }
    int T;
    std::cin >> T;
    while (T--) {
        i64 N;
        std::cin >> N;
        std::cout << (lose.contains(N) ? "xr" : "wty") << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}