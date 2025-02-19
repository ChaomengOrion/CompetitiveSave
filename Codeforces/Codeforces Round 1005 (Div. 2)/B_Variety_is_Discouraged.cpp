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
    std::map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        cnt[arr[i]]++;
    }
    int l = 0, r = -1, t = -1;
    for (int i = 0; i < N; i++) {
        if (cnt[arr[i]] == 1) {
            if (t == -1) {
                t = i;
            }
            if (i - t > r - l) {
                l = t;
                r = i;
            }
        } else {
            t = -1;
        }
    }
    if (r == -1) {
        std::cout << 0 << '\n';
        return;
    }
    std::cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}