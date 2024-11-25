#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                         \
    std::cerr << #_vec << " = " << '[';           \
    for (int _i = 0; _i < (_size); _i++) {        \
        std::cerr << (_vec)[_i];                  \
        if (_i != (_size) - 1) std::cerr << ", "; \
    }                                             \
    std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    if (N % 2 == 0) {
        int id = 0;
        for (int i = 0; i < N; i += 2) {
            id++;
            std::cout << id << ' ' << id << ' ';
        }
        std::cout << std::endl;
    } else if (N >= 27) {
        std::cout << "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 13 12 12 1 13 ";
        int id = 13;
        for (int i = 27; i < N; i += 2) {
            id++;
            std::cout << id << ' ' << id << ' ';
        }
        std::cout << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}