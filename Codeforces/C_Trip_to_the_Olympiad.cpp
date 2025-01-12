#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

//! 令a,b为pre + 0 + 11111111 / pre + 1 + 00000000, 更简单
void solve() {
    int L, R;
    std::cin >> L >> R;
    std::bitset<32> max = R;
    std::bitset<32> min = L;
    for (int i = 0; i < 32; i++) {
        if (min[i] == 0 && max[i] == 0) {
            min[i] = 1;
            if (min.to_ullong() > max.to_ullong()) {
                min[i] = 0;
            }
        } else if (min[i] == 1 && max[i] == 1) {
            max[i] = 0;
            if (min.to_ullong() > max.to_ullong()) {
                max[i] = 1;
            }
        }
    }
    int a = min.to_ullong(), b = max.to_ullong();
    int c = a + 1;
    if (c == b) {
        if (a != L) c = a - 1;
        else c = a + 2;
    }
    std::cout << a << ' ' << b << ' ' << c << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}