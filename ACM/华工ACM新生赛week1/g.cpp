#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;
const int P = 1E7;

void solve() {
    int k, S;
    std::cin >> k >> S;
    std::vector<int> ans;
    for (int i = 1; i <= k - 1; i++) {
        ans.push_back(P + i);
    }
    ans.push_back(-(k - 1) * P - k * (k - 1) / 2 + S);
    for (int i = 0; i < k; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}