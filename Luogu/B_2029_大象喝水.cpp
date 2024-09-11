#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) for (int i = 0; i < size; i++) { std::cout << vec[i]; } std::cout << std::endl;
#define PI 3.14f

void solve()
{
    int h, r;
    std::cin >> h >> r;
    float v = PI * r * r * h;
    int n = (int)(20000.0f / v);
    if (20000.0f - n * v > 0) n++;
    std::cout << n << std::endl;
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