#include <bits/stdc++.h>

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

int getd(i64 n) {
    int digit = 0;
    while (n > 0) {
        n /= 10;
        digit++;
    }
    return digit;
}

void solve() {
    i64 N;
    std::cin >> N;
    std::vector<i64> ans;
    for (int y = 1; y <= 9; y++) {
        i64 a = 99999999999LL * y - N;
        if (a % 9 == 0) {
            i64 x = a / 9;
            i64 n = x * 10 + y;
            if (getd(n) == 12) ans.emplace_back(n);
        }
    }
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << std::endl;
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}