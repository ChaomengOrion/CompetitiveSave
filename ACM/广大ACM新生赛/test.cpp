#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << (n / 5) * (m / 5) / 3 << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}