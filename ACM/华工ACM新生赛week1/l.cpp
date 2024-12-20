#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> seq(N + 1);
    std::vector<int> index(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
        index[seq[i]] = i;
    }
    int l = index[1], r = index[1];
    int cnt = 1, ans = 1;
    for (int i = 2; i <= N; i++) {
        int curIndex = index[i];
        if (curIndex > l) {
            l = curIndex;
        } else if (curIndex < r) {
            r = curIndex;
        }
        cnt++;
        if (cnt == l - r + 1) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}