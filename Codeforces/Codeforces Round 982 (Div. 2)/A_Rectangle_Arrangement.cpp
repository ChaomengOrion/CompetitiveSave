#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> rects(N);
    for (int i = 0; i < N; i++) {
        std::cin >> rects[i].first >> rects[i].second;
    }
    int maxa = INT_MIN, maxb = INT_MIN;
    for (auto [a, b] : rects) {
        maxa = std::max(maxa, a);
        maxb = std::max(maxb, b);
    }
    std::cout << 2 * (maxa + maxb) << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}