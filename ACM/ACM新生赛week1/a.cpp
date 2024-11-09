#include <bits/stdc++.h>

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;
using d64 = long double;

d64 getK(d64 x1, d64 y1, d64 x2, d64 y2) {
    return (y1 - y2) / (x1 - x2);
}

d64 getB(d64 x1, d64 y1, d64 x2, d64 y2) {
    return getK(x1, y1, x2, y2) * (-x1) + y1;
}

d64 getDis(d64 x, d64 y) {
    return sqrtl(x * x + y * y);
}

std::pair<bool, d64> tryQ(d64 x1, d64 y1, d64 x2, d64 y2) {
    if (x1 == x2) {
        d64 dis = fabsl(x1);
        bool inner = y1 * y2 < 0;
        return {inner, dis};
    } else if (y1 == y2) {
        d64 dis = fabsl(y1);
        bool inner = x1 * x2 < 0;
        return {inner, dis};
    } else {
        d64 k = getK(x1, y1, x2, y2);
        d64 b = getB(x1, y1, x2, y2);
        d64 dis = fabsl(b) / sqrtl(1 + k * k);
        //d64 kc = - 1 / k;
        d64 xc = (k * x1 - y1) / (k + 1 / k);
        d64 yc = (-1 / k) * xc;
        if (x1 > x2) std::swap(x1, x2);
        if (y1 > y2) std::swap(y1, y2);
        bool inner = (x1 <= xc && xc <= x2) && (y1 <= yc && yc <= y2);
        return {inner, dis};
    }
}

std::pair<d64, d64> getRange(d64 x1, d64 y1, d64 x2, d64 y2) {
    d64 l = getDis(x1, y1), r = getDis(x2, y2);
    if (l > r) std::swap(l, r);
    auto [inner, dis] = tryQ(x1, y1, x2, y2);
    if (inner) {
        l = dis;
    }
    return {l, r};
}

void solve() {
    int N;
    std::cin >> N;
    std::cout << std::fixed << std::setprecision(10);
    std::vector<std::array<int, 4>> lines(N);
    for (int i = 0; i < N; i++) {
        std::cin >> lines[i][0] >> lines[i][1] >> lines[i][2] >> lines[i][3];
    }
    auto [l, r] = getRange(lines[0][0], lines[0][1], lines[0][2], lines[0][3]);
        //LOG("cur lr is " << l << " " << r)
    for (int i = 1; i < N; i++) {
        auto [lc, rc] = getRange(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
        //LOG(lc << " " << rc)
        if (lc > r || rc < l) {
            std::cout << -1 << std::endl;
            return;
        }
        l = std::max(l, lc);
        r = std::min(r, rc); // 交集
        //LOG("cur lr is " << l << " " << r)
    }
    std::cout << l << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}