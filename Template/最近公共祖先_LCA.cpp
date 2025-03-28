#include <bits/stdc++.h>

using i64 = long long;

struct node {
    std::vector<int> to;
    int depth = -1;
};

void solve() {
    int N, Q, S;
    std::cin >> N >> Q >> S;
    std::vector<node> tree(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        tree[u].to.push_back(v);
        tree[v].to.push_back(u);
    }

    std::array<std::vector<int>, 20> f;
    std::fill(f.begin(), f.end(), std::vector<int>(N + 1, 0));

    auto dfs_dep = [&](auto&& self, int x, int dep, int fa) -> void {
        if (tree[x].depth != -1) return;
        tree[x].depth = dep;
        f[0][x] = fa;
        for (int son : tree[x].to) {
            self(self, son, dep + 1, x);
        }
    };

    dfs_dep(dfs_dep, S, 1, 0);

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= N; j++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }

    auto get_lca = [&](int a, int b) -> int {
        if (tree[a].depth > tree[b].depth) std::swap(a, b); // a <= b
        int gap = tree[b].depth - tree[a].depth, cnt = 0;
        while (gap) { //? 补齐到同一个高度
            if (gap & 1) {
                b = f[cnt][b];
            }
            cnt++;
            gap >>= 1;
        }
        if (a == b) return a;
        for (int i = 19; i >= 0; i--) { //? 在同一个高度基础上往上跳，跳到最近公共祖先的子节点
            if (f[i][a] != f[i][b]) {
                a = f[i][a];
                b = f[i][b];
            }
        }
        return f[0][a];
    };

    while (Q--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << get_lca(a, b) << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}