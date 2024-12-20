#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::set<int> canUse;
    for (int i = 1; i <= N; i++) {
        canUse.emplace(i);
    }
    for (int i = 1; i <= N; i++) {
        int need;
        std::cin >> need;
        int ans;
        if (canUse.contains(need)) {
            ans = need;
            canUse.erase(need);
        } else {
            ans = *canUse.begin();
            canUse.erase(canUse.begin());
        }
        std::cout << ans << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}