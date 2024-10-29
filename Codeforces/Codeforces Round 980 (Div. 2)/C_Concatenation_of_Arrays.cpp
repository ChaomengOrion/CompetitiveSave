#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> pairs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> pairs[i].first >> pairs[i].second;
    }
    auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool {
        int amin = std::min(a.first, a.second);
        int bmin = std::min(b.first, b.second);
        if (amin == bmin) {
            int amax = std::max(a.first, a.second);
            int bmax = std::max(b.first, b.second);
            return amax < bmax;
        }
        return amin < bmin;
    };
    std::sort(pairs.begin(), pairs.end(), cmp);
    for (auto [a, b] : pairs) {
        std::cout << a << ' ' << b << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}