#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::map<int, int> set;
    set.emplace(arr[0], 0);
    for (int i = 1; i < N; i++) {
        auto rit = set.lower_bound(arr[i]);
        auto lit = set.upper_bound(arr[i]);
        int dis = INT_MAX, index = -1;
        if (rit != set.end()) {
            int rv = rit->first;
            dis = rv - arr[i];
            index = rit->second;
        }
        if (lit != set.begin()) {
            int lv = std::prev(lit)->first;
            if (arr[i] - lv <= dis) {
                dis = arr[i] - lv;
                index = std::prev(lit)->second;
            }
        }
        std::cout << dis << ' ' << index + 1 << std::endl;
        set.emplace(arr[i], i);
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}