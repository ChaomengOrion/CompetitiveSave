#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<i64, i64>> arrs(N);
    for (int i = 0; i < N; i++) {
        i64 sum = 0, pre = 0;
        for (int j = 0; j < M; j++) {
            i64 temp;
            std::cin >> temp;
            sum += temp;
            pre += temp * (M - j);
        }
        arrs[i] = {sum, pre};
    }
    std::sort(arrs.begin(), arrs.end(), std::greater());
    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        auto [sum, pre] = arrs[i];
        int h = (N - i - 1) * M;
        ans += pre + sum * h;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}