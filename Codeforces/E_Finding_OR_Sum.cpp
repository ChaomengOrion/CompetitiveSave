#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

void solve() {
    const int A = 0b010101010101010101010101010101;
    const int B = 0b101010101010101010101010101010;
    std::cout << A << '\n' << B << '\n';
    int a, b;
    std::cin >> a >> b;
    std::bitset<32> even = a - (A << 1); // X{even} + Y{even}
    std::bitset<32> odd = b - (B << 1); // X{odd} + Y{odd}
    std::array<short, 32> cnt = {};
    for (int i = 0; i < 32; i++) {
        if (odd[i]) {
            if (i % 2 == 0) {
                cnt[i] += 1;
            } else {
                cnt[i - 1] += 2;
            }
        }
        if (even[i]) {
            if (i % 2 == 1) {
                cnt[i] += 1;
            } else if (i > 0) {
                cnt[i - 1] += 2;
            }
        }
    }
    std::cout << "!\n";
    int M;
    std::cin >> M;
    int carry = 0;
    std::bitset<32> m = M, add = 0;
    for (int i = 0; i < 32; i++) {
        if (!m[i]) {
            carry += cnt[i];
        }
        add[i] = carry % 2;
        carry = carry > 1;
    }
    std::cout << (M << 1) + add.to_ulong() << '\n';
}

int main() {
    std::cin.sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}