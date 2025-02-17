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
    i64 ans = 0;
    std::map<int, i64> lsum, rsum;
    i64 temp = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            temp += arr[i];
            lsum[i] = temp;
        }
    }
    temp = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            temp += -arr[i];
            rsum[i] = temp;
        }
    }
    auto getL = [&](int x) -> i64 {
        auto it = lsum.lower_bound(x);
        if (it == lsum.begin()) return 0;
        return prev(it)->second;
    };
    auto getR = [&](int x) -> i64 {
        auto it = rsum.upper_bound(x);
        if (it == rsum.end()) return 0;
        return it->second;
    };
    temp = 0;
    for (int i = -1; i < N; i++) {
        ans = std::max(ans, getL(i+1) + getR(i));
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}