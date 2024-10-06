#include <bits/stdc++.h>
using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size)                     \
    std::cerr << #vec << " = " << '[';        \
    for (int i = 0; i < size; i++) {          \
        std::cerr << vec[i];                  \
        if (i != size - 1) std::cerr << ", "; \
    }                                         \
    std::cerr << ']' << std::endl;

int fa[500010], h[500010], l[500010];
const int N = 100010;

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve()
{
    int n;
    std::cin >> n;
    i64 ans = 0;
    for (int i = 1; i <= N + N; ++i) // 因为最多有1e5行和1e5列因此要全部初始化
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        int fx = find(x);
        int fy = find(y + N);
        if (fx != fy) // 并
        {
            fa[fx] = fy;
        }
    }
    for (int i = 1; i <= N; ++i) {
        ++h[find(i)]; // 一行最多的个数
    }
    for (int i = N + 1; i <= N + N; ++i) {
        ++l[find(i)];
    }
    for (int i = 1; i <= N + N; ++i) {
        ans += 1LL * h[i] * l[i];
    }
    std::cout << ans - n << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}