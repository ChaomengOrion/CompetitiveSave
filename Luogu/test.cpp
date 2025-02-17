#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    std::vector<int> arr {0, 1, 3 ,4, 5};
    auto it = std::upper_bound(arr.begin() + 1, arr.end(), 5);
    std::cout << it - (arr.begin() + 1) << '\n';
    std::cout << std::distance(arr.begin() + 1, it) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}