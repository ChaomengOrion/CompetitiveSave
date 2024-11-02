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

void solve()
{
    int N;
    std::cin >> N;
    int cnt1 = 0;
    for (int i = 0; i < N * 2; i++) {
        int temp;
        std::cin >> temp;
        cnt1 += temp;
    }
    int min = cnt1 % 2;
    int max;
    if (cnt1 <= N) {
        max = cnt1;
    } else {
        max = N * 2 - cnt1;
    }
    std::cout << min << ' ' << max << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}