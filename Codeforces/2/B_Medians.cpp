#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                         \
    std::cerr << #_vec << " = " << '[';           \
    for (int _i = 0; _i < (_size); _i++) {        \
        std::cerr << (_vec)[_i];                  \
        if (_i != (_size) - 1) std::cerr << ", "; \
    }                                             \
    std::cerr << ']' << std::endl;

void solve() {
    int N, K;
    std::cin >> N >> K;
    if (N == 1 && K == 1) {
        std::cout << 1 << std::endl;
        std::cout << 1 << std::endl;
        return;
    }
    if (K == N || K == 1) {
        std::cout << -1 << std::endl;
        return;
    }
    int left = K - 1, right = N - K;
    if (left == 1 && right == 1) {
        std::cout << 3 << std::endl;
        std::cout << 1 << ' ' << 2 << ' ' << 3 << std::endl;
        return;
    }
    if (K % 2 == 0) {
        std::cout << 3 << std::endl;
        std::cout << 1 << ' ' << K << ' ' << K + 1 << std::endl;
    } else {
        if (left == 1 || right == 1) {
        std::cout << -1 << std::endl;
        return;
        }
        std::cout << 5 << std::endl;
        std::cout << 1 << ' ' << 2 << ' ' << K << ' ' << K + 1 << ' ' << K + 2 << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}