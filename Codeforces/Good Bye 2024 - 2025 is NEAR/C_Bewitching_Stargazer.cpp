#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    i64 n, k;
    std::cin >> n >> k;

    i64 mx = n;
    i64 min = -1;
    i64 mul = 1;
    i64 cnt = 0;
    while (mx >= k) {
        if (mx % 2 == 1) {
            min = (mx + 1) / 2;
            cnt += mul;
            }
            mx /= 2;
            mul *= 2;
    }
    if (min == -1) {
        std::cout << 0 << std::endl;
        return;
    }

    i64 l = min, r = n - min + 1;

    //LOG(l << ' ' << r << ' ' << cnt);

    i64 ans = (l + r) * cnt / 2;

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; 
    std::cin >> t; 
    while (t--) solve();
    return 0;
}