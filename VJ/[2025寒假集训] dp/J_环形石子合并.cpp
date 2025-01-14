#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(2 * N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        arr[i + N] = arr[i];
    }

    std::vector<int> pre(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++) {
        pre[i] = arr[i - 1] + pre[i - 1];
    }

    std::vector dp_min(2 * N, std::vector<int>(2 * N, INT_MAX));
    std::vector dp_max(2 * N, std::vector<int>(2 * N, INT_MIN));

    for (int i = 0; i < 2 * N; i++) {
        dp_max[i][i] = 0;
        dp_min[i][i] = 0;
    }

    for (int len = 1; len < 2 * N; len++) {
        for (int l = 0; l < 2 * N - len; l++) {
            int r = l + len;
            int sum = pre[r + 1] - pre[l];
            for (int k = l; k < r; k++) {
                dp_max[l][r] = std::max(dp_max[l][r], dp_max[l][k] + dp_max[k + 1][r] + sum);
                dp_min[l][r] = std::min(dp_min[l][r], dp_min[l][k] + dp_min[k + 1][r] + sum);
            }
        }
    }

    int mx = INT_MIN, mn = INT_MAX;

    for (int i = 0; i < N; i++) {
        int l = i, r = i + N - 1;
        mx = std::max(mx, dp_max[l][r]);
        mn = std::min(mn, dp_min[l][r]);
    }
    std::cout << mn << std::endl;
    std::cout << mx << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}