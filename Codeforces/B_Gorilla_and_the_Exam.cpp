#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        cnt[temp]++;
    }
    std::multimap<int, int> inv;
    for (auto [v, c] : cnt) {
        inv.insert({c, v});
    }

    while (K > 0) {
        if (inv.size() <= 1) break;
        int need = inv.begin()->first;
        K -= need;
        if (K >= 0) inv.erase(inv.begin());
        else break;
    }

    std::cout << inv.size() << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}