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

    std::vector<bool> closed(N + 1);

    { //* 计算闭合环
        std::vector<int> fa(N + 1);
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
    }

    //LOGV(closed, N + 1)
    { //* 计算并查集大小
        std::vector<int> fa(N + 1);
        std::vector<int> cnt(N + 1);
        for (int i = 1; i <= N; i++) {
            fa[i] = i;
            if (!closed[i]) cnt[i] = 1;
        }

        auto find = [&](auto&& find, int x) -> int {
            return x == fa[x] ? x : fa[x] = find(find, fa[x]);
        };

        auto merge = [&](int a, int b) -> void {
            if (closed[b]) return;
            if (find(find, a) != find(find, b)) {
                cnt[fa[b]] += cnt[fa[a]];
                fa[a] = fa[b];
            }
        };

        for (int i = 1; i <= N; i++) {
            if (closed[i]) continue;
            merge(i, to[i]);
        }

        //LOGV(fa, N + 1)
        //LOGV(cnt, N + 1)
        std::cout << 2 + *std::max_element(cnt.begin(), cnt.end()) << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}