#include <bits/stdc++.h>

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

using i64 = long long;

i64 binpow(i64 a, i64 b, i64 mod) {
    i64 ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
        static int case_cnt = 0;
        int N;
        i64 K, mod;
        std::cin >> N >> K >> mod;
        std::vector<i64> arr(N + 1);
        i64 sum = 0;

        for (int i = 1; i <= N; i++) {
            std::cin >> arr[i];
            sum = (sum + arr[i]) % mod;
        }

        sum = (sum * K) % mod * binpow((i64)N, K - 1, mod) % mod;
        std::cout << "Case " << ++case_cnt << ": " << sum << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}