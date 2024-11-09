#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) \
    std::cerr << #_vec << " = " << '[';\
    for (int _i = 0; _i < (_size); _i++) {\
        std::cerr << (_vec)[_i];\
        if (_i != (_size) - i) std::cerr << ", ";\
    }
using i64 = long long;

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> ranges(N);
    for (int i = 0; i < N; i++) {
        std::cin >> ranges[i].first >> ranges[i].second;
    }


}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}