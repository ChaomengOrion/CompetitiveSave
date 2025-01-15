#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[b].push_back(a);
    }
    std::vector<int> max(N + 1);
    auto dfs = [&](auto&& self, int x, int pa) -> void {
        if (max[x]) return;
        max[x] = pa;
        for (int to : graph[x]) {
            self(self, to, pa);
        }
    };
    for (int i = N; i >= 0; i--) {
        dfs(dfs, i, i);
    }
    for (int i = 0; i < N; i++) {
        std::cout << max[i + 1] << ' ';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}