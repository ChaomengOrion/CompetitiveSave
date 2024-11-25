#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> seq(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> seq[i];
    }
    for (int i = 1; i <= n; i++) {
        if (seq[i] != i) {
            if (seq[i] == i + 1 && seq[i + 1] == i) {
                i++;
                continue;
            }
            std::cout << "NO" << std::endl;
            return;
        }
    }
    std::cout << "YES" << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}