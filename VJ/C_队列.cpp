#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<bool> map(N * N);
    std::vector<int> cnt(N * N);
    std::vector<int> fa(N * N, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch;
            std::cin >> ch;
            map[i * N + j] = ch == '1';
        }
    }

    auto dfs = [&](auto&& self, int r, int c, int f, bool need1) -> void {
        if (fa[r * N + c] != -1) return;
        LOG(r << ' ' << c)
        bool ok = map[r * N + c] == need1;
        if (ok) {
            fa[r * N + c] = f;
            cnt[f] += 1;
            LOG(r << ',' << c << " f= " << fa[r * N + c] << " cnt[f]=" << cnt[f]);
            if (r + 1 < N) self(self, r + 1, c, f, !need1);
            if (r - 1 >= 0) self(self, r - 1, c, f, !need1);
            if (c + 1 < N) self(self, r, c + 1, f, !need1);
            if (c - 1 >= 0) self(self, r, c - 1, f, !need1);
        }
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            LOG("in: " << i << ' ' << j)
            dfs(dfs, i, j, i * N + j, map[i * N + j]);
        }
    }

    while (M--) {
        int r, c;
        std::cin >> r >> c;
        r--; c--;
        LOG("rc" << r << ',' << c << ", out: " << r * N + c << " f = " << fa[r * N + c])
        std::cout << cnt[fa[r * N + c]] << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}