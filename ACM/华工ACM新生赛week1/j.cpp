#include <bits/stdc++.h>

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

int cal2(int x1, int x2, int y1, int y2) { // x1 + x2 == y1 + y2
    return std::max(0, std::min(std::min(x1 - 1, x2 - 1), std::min(y1 - 1, y2 - 1)));
}

int cal3(int x1, int x2, int x3, int y1, int y2, int y3) {
    int ans = 0;
    for (int i = 1; i <= std::min(x1, y1) - 2; i++) {
        for (int j = 1; j < x1 - i; j++) {
            int k = x1 - i - j;
            for (int m = 1; m < y1 - i; m++) {
                int n = y1 - i - m;
                ans += cal2(x2 - m, x3 - n, y2 - j, y3 - k);
            }
        }
    }
    return ans;
}

void solve() {
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
    std::cout << cal3(x1, x2, x3, y1, y2, y3) << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}