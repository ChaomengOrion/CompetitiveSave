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

const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector graph(n + 1, std::vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    i64 ans = m % mod;

    auto dfs = [&](auto&& dfs, int u, int f, int de) -> void {
        i64 t = m - std::min(de + 1, 2);
        for (auto v : graph[u]) {
            if (v == f) continue;
            ans = ans * t % mod;
            t--;
        }
        for (auto v : graph[u])
            if (v != f) dfs(dfs, v, u, de + 1);
    };

    dfs(dfs, 1, -1, 0);
    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}