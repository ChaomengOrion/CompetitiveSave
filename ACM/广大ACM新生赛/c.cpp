#include <bits/stdc++.h>

using i64 = long long;
using d64 = long double;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

void solve() {
    d64 ax, ay, cx, cy, dx, dy;
    std::cin >> ax >> ay >> cx >> cy >> dx >> dy;
    d64 bx = ax + (cx - ax) / 3;
    d64 by = ay + (cy - ay) / 3;
    std::cout << std::fixed << std::setprecision(0);
    std::cout << (bx - dx) * (bx - dx) + (by - dy) * (by - dy) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}