#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    std::sort(B.begin(), B.end());

    auto get = [&](int last, int cur) -> int {
        auto it = std::lower_bound(B.begin(), B.end(), last + cur);
        if (it != B.end()) {
            if (cur >= last)
                return std::min(*it - cur, cur);
            return *it - cur;
        }
        if (cur >= last)
            return cur;
        return INT_MAX;
    };

    int last = std::min(arr[0], B[0] - arr[0]);
    for (int i = 1; i < N; i++) {
        last = get(last, arr[i]);
        if (last == INT_MAX) return void(std::cout << "NO" << '\n');
    }
    std::cout << "YES" << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}