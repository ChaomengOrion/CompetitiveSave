#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n, p;
    std::cin >> n >> p;
    std::vector<int> grades(n);
    for (int i = 0; i < n; i++) {
        std::cin >> grades[i];
    }
    // 求差分数组
    std::vector<int> D(n);
    D[0] = grades[0];
    for (int i = 1; i < n; i++) {
        D[i] = grades[i] - grades[i - 1];
    }
    while (p--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--, y--;
        D[x] += z;
        if (y + 1 < n) D[y + 1] -= z;
    }
    int cur = 0, min = INT_MAX;
    for (int i = 0; i < n; i++) {
        cur += D[i];
        min = std::min(min, cur);
    }

    std::cout << min << std::endl;
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