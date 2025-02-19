#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::map<int, bool> cnt;
    std::vector map(N, std::vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt[map[i][j]];
            if (i > 0 && map[i - 1][j] == map[i][j]) cnt[map[i][j]] = true;
            if (j > 0 && map[i][j - 1] == map[i][j]) cnt[map[i][j]] = true;
        }
    }
    int ans = 0;
    bool flag = false;
    for (auto [k, v] : cnt) {
        if (v == true) {
            flag = true;
        }
        if (v == false) {
            ans += 1;
        } else {
            ans += 2;
        }
    }
    if (flag) {
        ans -= 2;
    } else {
        ans -= 1;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}