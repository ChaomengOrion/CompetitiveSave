#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

bool canPaint(const std::vector<i64>& a, i64 k) {
    int n = a.size();
    if (n == 1) return true;
    std::set<i64> set(a.begin(), a.end());
    int cnt = 0;
    while (!set.empty()) {
        i64 num = *set.begin();
        if (set.size() > 1 && *std::next(set.begin()) - num <= k) {
            set.erase(set.begin());
            set.erase(set.begin());
        } else {
            set.erase(set.begin());
            cnt++;
        }
    }
    return cnt <= 1;
}

i64 minKToPaint(std::vector<i64>& a) {
    i64 left = 1, right = 1e18;
    while (left < right) {
        i64 mid = left + (right - left) / 2;
        if (canPaint(a, mid)) {
            right = mid; // 可能的解，尝试更小的 k
        } else {
            left = mid + 1; // 不行，需要更大的 k
        }
    }
    return left; // 最小的 k
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<i64> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::cout << minKToPaint(a) << std::endl;
    }
    return 0;
}
