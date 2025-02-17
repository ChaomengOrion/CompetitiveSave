#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int K;
    std::cin >> K; 
    int last = std::min(arr[0], K - arr[0]);
    for (int i = 1; i < N; i++) {
        if (K - arr[i] < last && arr[i] < last) {
            std::cout << "NO" << '\n';
            return;
        }
        int a = INT_MAX, b = INT_MAX;
        if (K - arr[i] >= last) {
            a = K - arr[i];
        }
        if (arr[i] >= last) {
            b = arr[i];
        }
        last = std::min(a, b);
    }
    std::cout << "YES" << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}