#include <bits/stdc++.h>

struct DSU {
    std::vector<int> fa;
    std::vector<int> dis;

    DSU(int size) 
    : fa(std::vector<int>(size + 1)), 
    dis(std::vector<int>(size + 1)) {
        std::iota(fa.begin() + 1, fa.end(), 1);
    }

    int find(int x) {
        if (fa[x] == x) return x;
        int p = fa[x];
        fa[x] = find(fa[x]);
        dis[x] += dis[p];
        return fa[x];
    }

    //* a.root -> b.root
    void merge(int a, int b, int d) {
        int ra = find(a), rb = find(b);
        if (ra != rb) {
            fa[ra] = rb;
            dis[ra] = dis[b] - dis[a] + d; //? 四边形等式
        }
    }
};

void solve() {
    int N, K;
    std::cin >> N >> K;
    DSU dsu(N);
    int ans = 0;
    while (K--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (x > N || y > N || (op == 2 && x == y)) {
            ans++;
            continue;
        }
        if (dsu.find(x) == dsu.find(y)) {
            int dis = (dsu.dis[y] - dsu.dis[x] + 300000000) % 3;
            if (dis != op - 1) {
                ans++;
                continue;
            }
        } else {
            dsu.merge(y, x, op - 1);
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}