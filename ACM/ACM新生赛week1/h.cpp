#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> attack(N);
    for (int i = 0; i < N; i++) {
        std::cin >> attack[i];
    }

    int min = INT_MAX;
    auto dfs = [&](auto&& dfs, int pre, int pos, int lastUse) -> void {
        if (pos == N) {
            min = std::min(min, pre);
            return;
        }
        // 闪避
        if (pos - lastUse > 2) dfs(dfs, pre, pos + 1, pos);
        // 不闪
        if (pos - lastUse == 1) {
            dfs(dfs, pre, pos + 1, lastUse);
        }
        else dfs(dfs, pre + attack[pos], pos + 1, lastUse);
    };
    dfs(dfs, 0, 0, -10);
    std::cout << min + 1;
}

int main() {
    solve();
    return 0;
}