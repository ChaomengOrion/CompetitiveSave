#include <bits/stdc++.h>
#define CFMode

using i64 = long long;
using u64 = unsigned long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) //std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    i64 n, q;
    std::cin >> n >> q;
    std::vector<i64> X(n);
    for (i64 i = 0; i < n; i++) {
        std::cin >> X[i];
    }
    std::map<u64, u64> map; // k, cnt
    u64 cnt_sum = n * (n - 1) / 2;
    i64 prev = 0;
    for (i64 i = 0; i < n; i++) {
        if (X[i] > X[prev] + 1) {
            u64 left = i, right = n - i;
            u64 cnt = cnt_sum - left * (left - 1) / 2 - right * (right - 1) / 2;
            map[cnt] += X[i] - X[prev] - 1;
        }
        u64 left = i, right = n - i - 1;
        u64 cnt = cnt_sum - left * (left - 1) / 2 - right * (right - 1) / 2;
        map[cnt]++;
        prev = i;
    }
    while (q--) {
        u64 k;
        std::cin >> k;
        if (map.contains(k)) {
            std::cout << map[k] << ' ';
            continue;
        }
        std::cout << 0 << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}