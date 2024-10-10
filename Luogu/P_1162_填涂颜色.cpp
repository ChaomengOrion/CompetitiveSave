#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < _size; _i++) { std::cerr << _vec[_i]; if (_i != _size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const std::pair<int, int> DIR[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve()
{
    int N;
    std::cin >> N;
    std::vector map(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            std::cin >> c;
            map[i][j] = c == '1';
        }
    }

    std::vector vis(N, std::vector<bool>(N, false));
    std::queue<std::pair<int, int>> pending;
    std::queue<std::pair<int, int>> temp;
    auto bfs = [&]() -> void {
        bool toEdge = false;
        while (!pending.empty()) {
            auto [i, j] = pending.front();
            vis[i][j] = true;
            pending.pop();
            temp.emplace(i, j);

            for (auto [x, y] : DIR) {
                if (0 <= x + i && x + i < N && 0 <= y + j && y + j < N) {
                    if (!vis[x + i][y + j] && map[x + i][y + j] == 0) {
                        pending.emplace(x + i, y + j);
                        vis[x + i][y + j] = true;
                    }
                } else {
                    toEdge = true;
                    break;
                }
            }
        }
        if (!toEdge) {
            while (!temp.empty()) {
                auto [i, j] = temp.front();
                map[i][j] = 2;
                temp.pop();
            }
        } else {
            while (!temp.empty()) {
                temp.pop();
            }
        }
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0 && !vis[i][j]) {
                pending.emplace(i, j);
                bfs();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}