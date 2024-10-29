#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::cout << ((n & 1) ? "Kosuke" : "Sakurako") << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}