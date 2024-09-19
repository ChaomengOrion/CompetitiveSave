#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<std::string> svec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> svec[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        auto& s = svec[i];
        for (int r = 0; r < 4; r++) {
            if (s[r] == '#') {
                std::cout << r + 1 << ' ';
                break;
            }
        }
    }
    std::cout << std::endl;
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}