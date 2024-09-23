#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (i64 i = 0; i < n; i++) std::cin >> a[i];
    if (n <= 2) {
        std::cout << -1 << std::endl;
        return;
    }
    std::sort(a.begin(), a.end());
    i64 half_gold = a[n >> 1];

    i64 sum = 0;
    for (i64 i = 0; i < n; i++) sum += a[i];
    i64 avg_half = (sum + (n * 2) - 1) / (n * 2);
    if (half_gold < avg_half) {
        std::cout << 0 << std::endl;
        return;
    }
    else {
        i64 taget = half_gold * 2 * n + 1;
        std::cout << taget - sum << std::endl;
        return;
    }
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