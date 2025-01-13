// TODO: 2025-1-12

#include <bits/stdc++.h>
using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    i64 temp = exgcd(b, a % b, x, y);
    i64 t = x;
    x = y;
    y = t - a / b * y;
    return temp;
}


void solve() {
    i64 a, b, c, x1, x2, y1, y2;
    i64 ans = 0, x = 0, y = 0;
    std::cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    c = -c;
    if (a == 0 && b == 0) {
        if (c == 0) ans = (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    else if (a == 0) {
        if (c % b == 0 && c / b >= y1 && c / b <= y2)
            ans = x2 - x1 + 1;
    }
    else if (b == 0) {
        if (c % a == 0 && c / a >= x1 && c / a <= x2)
            ans = y2 - y1 + 1;
    }
    else {
        i64 d = exgcd(a, b, x, y);
        i64 mL[2], mR[2], t = -1;
        auto update = [&](i64 L, i64 R, i64 wa) {
            if (wa < 0) {
                L = -L, R = -R, wa = -wa;
                std::swap(L, R);
            }
            mL[++t] = (L <= 0) ? L / wa : (L - 1) / wa + 1 ;
            mR[t] = (R >= 0) ? R / wa : (R + 1) / wa - 1 ;
        };
        if (c % d == 0) {
            i64 p = c / d;
            update(x1 - p * x, x2 - p * x, b / d);
            update(y1 - p * y, y2 - p * y, -a / d);
            ans = std::min(mR[0], mR[1]) - std::max(mL[0], mL[1]) + 1;
            if (ans < 0) ans = 0;
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}