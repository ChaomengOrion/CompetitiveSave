#include <bits/stdc++.h>

using i64 = long long;
using d64 = long double;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

d64 cut3(d64 x) {
    while (x >= 1000.0l) {
        x /= 10.0l;
    }
    return x;
}

std::string high3(d64 a, i64 b)
{
    d64 ans = 1;
    while (b) {

        if (b % 2 == 1) ans = cut3(ans * a);
        a = cut3(a * a);
        b /= 2;
    }
    return std::to_string((int)cut3(ans));
}

std::string low3(i64 a, i64 b)
{
    i64 ans = 1;
    while (b) {

        if (b % 2 == 1) ans = ans * a % 1000;
        a = a * a % 1000;
        b /= 2;
    }
    auto s = std::to_string(ans % 1000);
    while (s.length() < 3) {
        s = '0' + s;
    }
    return s;
}

void solve() {
    static int cnt = 0;
    i64 n, k;
    std::cin >> n >> k;
    std::cout << "Case " << ++cnt << ": " << high3(n, k) << ' ' << low3(n, k) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}