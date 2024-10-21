#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    //std::vector<int> arr(n);
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        min = std::min(min, temp);
        max = std::max(max, temp);
    }
    std::cout << (max - min) * (n - 1) << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}