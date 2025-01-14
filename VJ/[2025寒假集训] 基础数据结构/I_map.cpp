#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::map<i64, i64> posMax;
    for (int i = 0; i < N; i++) {
        i64 a, b;
        std::cin >> a >> b;
        i64 c = a ^ b;
        posMax[a]++;
        if (c != a) {
            posMax[c]++;
        }
    }
    i64 maxCnt = -1, maxV = -1;
    for (auto [k, cnt] : posMax) {
        if (cnt > maxCnt) {
            maxCnt = cnt;
            maxV = k;
        }
    }

    std::cout << maxV << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}