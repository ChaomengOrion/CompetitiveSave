#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const int N = 16000;

void solve() {
    std::vector<bool> isP(N + 1, true);
    for (int i = 2; i <= N; i++) {
        if (!isP[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            isP[j] = false;
        }
    }
    isP[1] = false;
    isP[2] = false;
    int x, cnt = 0;
    while (std::cin >> x && x > 0) {
        std::cout << ++cnt << ": " << (isP[x] ? "yes" : "no") << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}