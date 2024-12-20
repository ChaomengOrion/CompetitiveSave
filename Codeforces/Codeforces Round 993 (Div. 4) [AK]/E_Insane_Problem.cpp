#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

inline i64 cal(i64 L1, i64 R1, i64 L2, i64 R2, i64 mul) {
    i64 mL1 = mul * L1;
    i64 mR1 = mul * R1;
    //if (mR1 < L2 || mL1 > R2) return 0LL;
    //if (mL1 >= L2 && mR1 <= R2) return R1 - L1 + 1;
    i64 no = std::max(0LL, L2 - mL1 + mul - 1) / mul + std::max(0LL, mR1 - R2 + mul - 1) / mul;
    //LOG(no)
    return std::max(0LL, R1 - L1 + 1 - no);
}

i64 binpow(i64 a, i64 b)
{
    // a %= m;
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a; // % m;
        a = a * a; // % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    i64 K, L1, R1, L2, R2;
    std::cin >> K >> L1 >> R1 >> L2 >> R2;
    i64 N = 0;
    i64 ans = 0;
    while (true) {
        i64 mul = binpow(K, N);
        i64 cnt = cal(L1, R1, L2, R2, mul);
        //LOG(mul << " - " << cnt)
        ans += cnt;
        if (L1 * mul > R2) break;
        N++;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}