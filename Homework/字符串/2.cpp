#include <bits/stdc++.h>

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector map(N, std::vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    
    std::string need;
    std::cin >> need;
    std::vector vis(N, std::vector<bool>(M, false)); // 记录每个点是否搜索过，初始为false

    auto check = [&](int x, int y) -> bool { // 确认x, y没有越界
        return x >= 0 && y >= 0 && x < N && y < N;
    };

    auto dfs = [&](auto&& dfs, int x, int y, int p) -> bool {
        if (p == need.size() - 1) return true; // p = need的长度 - 1，匹配成功
        if (vis[x][y]) return false; // 已经走过了这个点，返回失败
        vis[x][y] = true; // 标记这个点已经走过
        char next = need[p + 1]; // 下一个需要匹配的字符
        // 往四个方向找
        if (check(x + 1, y) && map[x + 1][y] == next && dfs(dfs, x + 1, y, p + 1)) return true;
        if (check(x - 1, y) && map[x - 1][y] == next && dfs(dfs, x - 1, y, p + 1)) return true;
        if (check(x, y + 1) && map[x][y + 1] == next && dfs(dfs, x, y + 1, p + 1)) return true;
        if (check(x, y - 1) && map[x][y - 1] == next && dfs(dfs, x, y - 1, p + 1)) return true;
        return false;
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == need[0]) {
                // 遇到need的开头字符，直接dfs搜索
                if (dfs(dfs, i, j, 0)) {
                    std::cout << "FOUND" << std::endl;
                    return;
                }
                vis = std::vector(N, std::vector<bool>(M, false)); // 重置vis
            }
        }
    }
    std::cout << "NOT FOUND" << std::endl;
}

int main() {
    solve();
}