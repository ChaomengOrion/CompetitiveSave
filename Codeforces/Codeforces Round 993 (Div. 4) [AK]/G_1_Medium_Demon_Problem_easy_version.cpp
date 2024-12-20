#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> to(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> to[i];
    }

    std::vector<int> fa(N + 1);
    std::vector<bool> closed(N + 1);

    for (int i = 1; i <= N; i++) {
        fa[i] = i;
    }

    auto find = [&](auto&& find, int x) -> int {
        return x == fa[x] ? x : fa[x] = find(find, fa[x]);
    };

    auto merge = [&](int a, int b) -> void {
        if (find(find, a) != find(find, b)) {
            fa[a] = fa[b];
        } else {
            int start = a, pos = a;
            do {
                closed[pos] = true;
                pos = to[pos];
            } while (pos != start);
        }
    };

    for (int i = 1; i <= N; i++) {
        merge(i, to[i]);
    }

    //LOGV(closed, N + 1)

    int maxDis = 0;
    std::vector<int> dis(N + 1);
    auto search = [&](auto&& search, int x) -> int {
        if (closed[x]) return 0;
        if (dis[x] != 0) return dis[x];
        return dis[x] = search(search, to[x]) + 1;
    };

    for (int i = 1; i <= N; i++) {
        if (closed[i]) continue;
        if (dis[i] != 0) continue;
        maxDis = std::max(maxDis, search(search, i));
    }

    std::cout << 2 + maxDis << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}