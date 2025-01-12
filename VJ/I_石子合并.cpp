#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> pre(N + 1);
    for (int i = 1; i <= N; i++) {
        pre[i] = arr[i - 1] + pre[i - 1];
    }

    std::vector dp_min(N, std::vector<int>(N, INT_MAX));

    for (int i = 0; i < N; i++) {
        dp_min[i][i] = 0;
    }

    for (int len = 1; len < N; len++) {
        for (int l = 0; l < N - len; l++) {
            int r = l + len;
            int sum = pre[r + 1] - pre[l];
            for (int k = l; k < r; k++) {
                dp_min[l][r] = std::min(dp_min[l][r], dp_min[l][k] + dp_min[k + 1][r] + sum);
            }
        }
    }

    std::cout << dp_min[0][N - 1] << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}