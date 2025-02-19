#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

struct DSU {
    std::vector<int> fa;

    DSU(int size) : fa(std::vector<int>(size + 1)) {
        std::iota(fa.begin() + 1, fa.end(), 1);
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    //* a.root -> b.root
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            fa[a] = fa[b];
        }
    }
};

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    DSU dsu(N);
    while (Q--) {
        int op, x, y; std::cin >> op >> x >> y;
        if (op == 1) {
            dsu.merge(x, y);
        } else {
            std::cout << (dsu.find(x) == dsu.find(y) ? "Y" : "N") << '\n';
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}