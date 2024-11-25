#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                         \
    std::cerr << #_vec << " = " << '[';           \
    for (int _i = 0; _i < (_size); _i++) {        \
        std::cerr << (_vec)[_i];                  \
        if (_i != (_size) - 1) std::cerr << ", "; \
    }                                             \
    std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::vector<i64> arr(N);
    std::map<i64, int> lastIndex;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) {
        lastIndex[arr[i]] = i;
    }
    int cnt = INT_MAX;
    for (int i = 0; i < N - 2; i++) {
        i64 add = arr[i] + arr[i + 1];
        int cost = N - 1 - prev(lastIndex.lower_bound(add))->second;
        cnt = std::min(cnt, cost + i);
    }
    std::cout << cnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}