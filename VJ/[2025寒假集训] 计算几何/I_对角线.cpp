#include <bits/stdc++.h>

using i64 = long long;
using d64 = long double;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    d64 N;
    std::cin >> N;
    std::cout << (i64)std::roundl(N * (N - 1) / 2LL * (N - 2) / 3LL * (N - 3) / 4LL) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}