#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

// 发现(K*X)^X 在 [(K-1)*X, (K+1)*X] 范围内
void solve() {
    i64 X, M;
    std::cin >> X >> M;

    i64 K = M / X;
    i64 cnt = std::max(0LL, K - 2);

    i64 tY = ((K * X) ^ X);
    cnt += tY <= M && tY > 0;
    tY = (((K + 1) * X) ^ X);
    cnt += tY <= M && tY > 0;

    // K = 0
    if (K > 0) {
        tY = X;
        cnt += tY <= M && tY > 0;
    }

    // K = 1 一定不行

    for (int y = 1; y <= std::min(M, X); y++) {
        K = X / y;
        i64 a = (K * y) ^ y;
        i64 b = ((K + 1) * y) ^ y;
        i64 c = -1;
        if (K > 0) c = ((K - 1) * y) ^ y;
        if ((a == X && K * y % X != 0) || (b == X && (K + 1) * y % X != 0) || (c == X && (K - 1) * y % X != 0)) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}