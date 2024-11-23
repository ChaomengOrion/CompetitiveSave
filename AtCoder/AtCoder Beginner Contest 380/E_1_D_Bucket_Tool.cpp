#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> fa(N + 1);
    std::vector<int> cnt(N + 1);
    std::vector<std::pair<int, int>> range(N + 1);
    std::vector<int> i2color(N + 1);
    std::vector<int> colorCnt(N + 1);

    auto cmp = [&](int a, int b) -> bool {
        return range[a] < range[b];
    };
    std::vector<std::set<int, decltype(cmp)>> color2i(N + 1, std::set<int, decltype(cmp)>(cmp));

    for (int i = 1; i <= N; i++) {
        fa[i] = i;
        i2color[i] = i;
        cnt[i] = 1;
        colorCnt[i] = 1;
        range[i] = {i, i};
        color2i[i].insert(i);
    }

    auto find = [&](auto&& find, int x) -> int {
        return x == fa[x] ? x : fa[x] = find(find, fa[x]);
    };

    auto set = [&](int x, int c) -> void {
        int rx = find(find, x);
        color2i[i2color[rx]].erase(rx);
        colorCnt[i2color[rx]] -= cnt[rx];
        i2color[rx] = c;
        std::vector<int> del, check;
        auto it = color2i[c].upper_bound(rx);
        if (it != color2i[c].end()) check.push_back(*it);
        if (it != color2i[c].begin()) check.push_back(*prev(it));
        for (int rc : check) {
            if (range[rx].second + 1 == range[rc].first || range[rc].second + 1 == range[rx].first) { // 满足合并条件
                fa[rc] = rx;
                del.push_back(rc);
                cnt[rx] += cnt[rc]; // 合并计数
                range[rx].first = std::min(range[rc].first, range[rx].first);
                range[rx].second = std::max(range[rc].second, range[rx].second); // 合并边界
            }
        }
        for (int rc : del) {
            color2i[c].erase(rc);
            colorCnt[c] -= cnt[rc];
        }
        color2i[c].insert(rx);
        colorCnt[i2color[rx]] += cnt[rx];
    };

    while (Q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, c;
            std::cin >> x >> c; 
            set(x, c);
        } else {
            int c;
            std::cin >> c;
            std::cout << colorCnt[c] << std::endl;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}