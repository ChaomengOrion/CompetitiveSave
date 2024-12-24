#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    i64 sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    bool has0 = false;
    for (int i = 1; i < N - 1; i++) {
        if (arr[i] == 0) {
            bool a = false, b = false;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] != 0) {
                    a = true;
                    break;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] != 0) {
                    b = true;
                    break;
                }
            }
            if (a && b) {
                has0 = true;
                break;
            }
        }
    }
    if (sum == 0) {
        std::cout << 0 << std::endl;
    } else if (!has0) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}