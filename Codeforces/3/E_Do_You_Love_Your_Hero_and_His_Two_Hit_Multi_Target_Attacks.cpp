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

int cal(int n) {
    return n * (n - 1) / 2;
}

void solve() {
    int N;
    std::cin >> N;
    int k = 500;
    int x = 0, y = 0;
    std::vector<std::pair<int, int>> ans;
    while (N > 0) {
        while (cal(k) > N) k--;
        int cur = cal(k);
        //LOG(k, cur, N);
        for (int i = 0; i < k; i++) {
            ans.emplace_back(x, y);
            x++;
        }
        y++;
        N -= cur;
    }
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}