#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> value(N + 1);
    std::vector<std::vector<int>> tree(N + 1);
    std::vector<int> fa(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        std::cin >> value[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int l, k;
        std::cin >> l >> k;
        tree[k].emplace_back(l);
        fa[l] = k;
    }
    std::vector<int> f(N + 1), // 来
                     g(N + 1); // 不来
    auto dfs = [&](auto&& self, int x) -> void {
        int sumg = 0, sumf = 0;
        for (int son : tree[x]) {
            self(self, son);
            sumf += g[son];
            sumg += std::max(f[son], g[son]);
        }
        sumf += value[x];
        f[x] = sumf;
        g[x] = sumg;
    };
    int root = 1;
    while (fa[root] != -1) {
        root = fa[root];
    }
    dfs(dfs, root);
    std::cout << std::max(f[root], g[root]) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}