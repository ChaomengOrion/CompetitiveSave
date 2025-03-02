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
    i64 N, L, R;
    std::cin >> N >> L >> R;
    std::vector<int> seq(N + 1);
    std::vector<int> pre(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
        pre[i] = seq[i] ^ pre[i - 1];
    }

    int fixed = N % 2 == 1 ? pre[N] ^ pre[0] : pre[N] ^ pre[N / 2];
    int start = N % 2 == 1 ? (N + 1) * 2 : (N + 2) * 2;

    auto down = [&](auto&& self, i64 x) -> int {
        if (x <= N) {
            return seq[x];
        }
        if (x / 2 <= N) {
            return pre[x / 2];
        }
        if (x < start) {
            return fixed;
        }
        if ((x - start) / 2 % 2 == 1) {
            return fixed;
        }
        return self(self, x / 2) ^ fixed;
    };

    std::cout << down(down, L) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}