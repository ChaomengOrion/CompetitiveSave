#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size)                     \
    std::cerr << '[';                         \
    for (int i = 0; i < size; i++) {          \
        std::cerr << vec[i];                  \
        if (i != size - 1) std::cerr << ", "; \
    }                                         \
    std::cerr << ']' << std::endl;

void solve()
{
    int n, d, k; // 总天数、访问持续时间和工作数量
    std::cin >> n >> d >> k;

    std::vector<int> a(n + 2), b(n + 2);
    for (int i = 0; i < k; i++) {
        int l, r;
        std::cin >> l >> r;
        a[l]++;
        b[r + 1]++;
    }

    for (int i = 1; i <= n + 1; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    int x = 0, y = 0, mx = 0, mn = INT_MAX;

    for (int i = 1; i + d - 1 <= n; i++) {
        int cur = a[i + d - 1] - b[i];

        if (cur > mx) {
            mx = cur;
            x = i;
        }
        if (cur < mn) {
            mn = cur;
            y = i;
        }
    }

    std::cout << x << " " << y << "\n";
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t;
    std::cin >> t;
    while (t--) solve();
#else
    solve();
#endif
    return 0;
}