#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M;
    std::cin >> M >> N;
    std::vector<std::array<int, 3>> items(N); // Wi Di 组别
    for (int i = 0; i < N; i++) {
        std::cin >> items[i][0] >> items[i][1] >> items[i][2];
    }
    std::sort(items.begin(), items.end(), [](const std::array<int, 3>& a, const std::array<int, 3>& b) {
        return a[2] < b[2];
    });

    std::vector<std::vector<std::pair<int, int>>> groups;
    int lastGroup = -1;
    for (int i = 0; i < N; i++) {
        if (items[i][2] != lastGroup) {
            lastGroup = items[i][2];
            groups.push_back(std::vector<std::pair<int, int>> {{items[i][0], items[i][1]}});
        } else {
            groups.back().push_back({items[i][0], items[i][1]});
        }
    }

    int cnt = groups.size();

    std::vector<int> dp(M + 1, 0), last(M + 1, 0);

    for (int i = 0; i < cnt; i++) { //* 类别
        for (int j = M; j >= 0; j--) { //* 容量，(倒序枚举?)
            int gm = 0;
            for (auto [cost, val] : groups[i]) { //* 组内物品
                if (j - cost >= 0) gm = std::max(gm, last[j - cost] + val);
            }
            dp[j] = std::max(last[j], gm);
        }
        std::swap(dp, last);
        std::fill(dp.begin(), dp.end(), 0);
    }

    std::cout << last.back() << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}