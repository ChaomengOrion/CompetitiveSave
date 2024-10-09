#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < _size; _i++) { std::cerr << _vec[_i]; if (_i != _size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector map(N, std::vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            std::cin >> c;
            map[i][j] = c == '#';
        }
    }

    auto needvis = map;

    auto dfs = [&](auto&& dfs, int i, int j) -> bool {
        bool flag = !(!map[i][j - 1] || !map[i - 1][j] || !map[i + 1][j] || !map[i][j + 1]);
        needvis[i][j] = false;
        if (needvis[i][j - 1]) flag |= dfs(dfs, i, j - 1);
        if (needvis[i - 1][j]) flag |= dfs(dfs, i - 1, j);
        if (needvis[i][j + 1]) flag |= dfs(dfs, i, j + 1);
        if (needvis[i + 1][j]) flag |= dfs(dfs, i + 1, j);
        return flag;
    };

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(needvis[i][j]) {
                if(!dfs(dfs, i, j)) cnt++;
            }
        }
    }

    std::cout << cnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}