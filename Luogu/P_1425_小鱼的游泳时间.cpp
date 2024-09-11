#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) for (int i = 0; i < size; i++) { std::cout << vec[i]; } std::cout << std::endl;

void solve()
{
    int sh, sm, eh, em;
    std::cin >> sh >> sm >> eh >> em;
    int t = (eh - sh) * 60 + em - sm;
    std::cout << t / 60 << ' ' << (t + 60) % 60 << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}