#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

// 题目要求：可以进行多次操作，在一次操作中，我们选择一个位置 i 并同时执行以下操作：a[i]=a[i]−1 和 a[i+1]=a[i+1]+1。找出 max(a1,a2,…,an)−min(a1,a2,…,an)的最小可能值。

void solve()
{
    int n; // 数组长度
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto checkMax = [a, n](i64 limit) -> bool {
        auto b = a;
        for (int i = 0; i < n - 1; i++) {
            if (b[i] > limit) {
                i64 diff = b[i] - limit;
                b[i] -= diff;
                b[i + 1] += diff;
            }
        }
        return b[n - 1] <= limit;
    };
    auto checkMin = [a, n](i64 limit) -> bool {
        auto b = a;
        for (int i = n - 1; i > 0; i--) {
            if (b[i] < limit) {
                i64 diff = limit - b[i];
                b[i] += diff;
                b[i - 1] -= diff;
            }
        }
        return b[0] >= limit;
    };
    auto [min, max] = std::minmax_element(a.begin(), a.end());
    i64 l = *min, r = *max;
    while (l < r) {
        i64 mid = (l + r) >> 1;
        if (checkMax(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    i64 mx = l;
    l = *min, r = *max;
    while (l < r) {
        i64 mid = (l + r + 1) >> 1;
        if (checkMin(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    i64 mn = l;
    std::cout << mx - mn << "\n";
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