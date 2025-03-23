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