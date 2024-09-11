#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) for (int i = 0; i < size; i++) { std::cout << vec[i]; } std::cout << std::endl;

void solve()
{
    float in;
    std::cin >> in;
    int n = in * 10;
    int ans = 0, cnt = 3;
    while (n > 0) {
        int i = cnt, cur = n % 10;
        while (i--) cur *= 10;
        ans += cur;
        n /= 10;
        cnt--;
    }
    std::cout << (float)ans / 1E3 << std::endl;
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