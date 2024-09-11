#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int ones, twos;
    std::cin >> ones >> twos;

    if (ones % 2)
    {
        std::cout << "NO" << std::endl;
        return;
    }
    if (twos % 2 == 0) {
        std::cout << "YES" << std::endl;
        return;
    }
    if (ones == 0) {
        std::cout << "NO" << std::endl;
        return;
    }
    std::cout << "YES" << std::endl;
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