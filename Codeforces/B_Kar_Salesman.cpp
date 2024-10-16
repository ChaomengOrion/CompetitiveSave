#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, X;
    std::cin >> N >> X;
    std::vector<int> cars(N);
    i64 sum = 0;
    int max = INT_MIN;
    for (int i = 0; i < N; i++) {
        std::cin >> cars[i];
        sum += cars[i];
        max = std::max(max, cars[i]);
    }
    i64 ans = std::max(1LL * max, // 至少操作次数（每次操作都包括最大的）
                       (sum + X - 1) / X); // 理论全不浪费时候的操作次数
    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}