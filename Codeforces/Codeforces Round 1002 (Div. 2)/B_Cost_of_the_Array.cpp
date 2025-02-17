#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int cnt = 1;
    int s = 1;
    while (s < N) {
        for (int i = s; i <= s + N - K; i++) {
            if (arr[i] != cnt) {
                std::cout << cnt << std::endl;
                return;
            }
        }
        cnt++;
        if (N - K > 0) {
            std::cout << cnt << std::endl;
            return;
        }
        s += 2;
    }
    std::cout << cnt << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}