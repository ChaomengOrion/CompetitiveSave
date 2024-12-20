#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        cnt[n % i]++;
    }
    
    while (q--)
    {
        int m, r;
        std::cin >> m >> r;
        if (r > n) {
            std::cout << "NO" << std::endl;
        } else if (r == n) {
            std::cout << "YES" << std::endl;
        } else {
            LOG("r: " << r << " cnt: " << cnt[r])
            std::cout << (cnt[r] >= m ? "YES" : "NO") << std::endl;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}