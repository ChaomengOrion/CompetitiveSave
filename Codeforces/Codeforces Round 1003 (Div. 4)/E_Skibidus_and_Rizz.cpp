#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N0, N1, K;
    std::cin >> N0 >> N1 >> K;
    std::string ans;
    int cnt0 = 0, cnt1 = 0;
    char last;
    if (N0 > N1) {
        if (N0 < K) {
            std::cout << -1 << '\n';
            return;
        }
        for (int i = 0; i < K; i++) {
            ans += '0';
        }
        last = '0';
        N0 -= K;
        cnt0 += K;
    } else {
        if (N1 < K) {
            std::cout << -1 << '\n';
            return;
        }
        for (int i = 0; i < K; i++) {
            ans += '1';
        }
        last = '1';
        N1 -= K;
        cnt1 += K;
    }
    while (N0 > 0 && N1 > 0) {
        if (last == '0') {
            N1--;
            ans += '1';
            last = '1';
            cnt1++;
        } else {
            N0--;
            ans += '0';
            last = '0';
            cnt0++;
        }
    }
    while (N0 > 0) {
        ans += '0';
        cnt0++;
        if (abs(cnt0 - cnt1) > K) {
            std::cout << -1 << '\n';
            return;
        }
        N0--;
    }
    while (N1 > 0) {
        ans += '1';
        cnt1++;
        if (abs(cnt0 - cnt1) > K) {
            std::cout << -1 << '\n';
            return;
        }
        N1--;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}