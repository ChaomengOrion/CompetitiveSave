#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;

struct node {
    std::vector<int> to;
    int degree;
    int degree_noleaf;
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<node> graph(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].to.emplace_back(v);
        graph[v].to.emplace_back(u);
    }

    for (int i = 1; i <= N; i++) {
        graph[i].degree = graph[i].to.size();
    }

    int cnt_leaf = 0, cnt_by = 0, cnt_normal = 0;
    for (int i = 1; i <= N; i++) {
        graph[i].degree_noleaf = 0;
        for (int j = 0; j < graph[i].degree; j++) {
            int to = graph[i].to[j];
            if (graph[to].degree > 1) {
                graph[i].degree_noleaf++;
            }
        }
        if (graph[i].degree == 1) {
            cnt_leaf++;
        } else if (graph[i].degree == graph[i].degree_noleaf) {
            cnt_normal++;
        } else {
            cnt_by++;
        }
    }

    //LOG(cnt_leaf << ' ' << cnt_by << ' ' << cnt_normal)
    i64 ans = 0;
    //* Type1: 直接赢
    ans += 1LL * cnt_leaf * (cnt_normal + cnt_by);
    //* Type2: 走一步赢
    for (int i = 1; i <= N; i++) {
        if (graph[i].degree == 1 || graph[i].degree == graph[i].degree_noleaf) {
            continue;
        }
        //* 找到by
        ans += 1LL * cnt_normal * (graph[i].degree_noleaf - 1);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}