#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;
    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        int a1 = std::max(x1, 0);
        int b1 = std::max(y1, 0);
        int a2 = std::min(x2, A);
        int b2 = std::min(y2, B);
        ans += (a2 - a1) * (b2 - b1);
    }
    std::cout << ans << std::endl;
}
