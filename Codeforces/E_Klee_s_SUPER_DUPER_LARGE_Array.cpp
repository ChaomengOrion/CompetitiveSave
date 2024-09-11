#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    i64 n, k;
    std::cin >> n >> k;

    i64 last = -1;
    i64 l = 0;
    i64 r = n;
    while (true) {
        i64 j = (r + l) / 2;
        //std::cout << j << ": " << ((k+k+j-1)*(j)/2) << ", " << ((k+j+k+n-1)*(n-j)/2) << std::endl;
        i64 ans = (1LL*(k+k+j-1)*(j)/2) - (1LL*(k+j+k+n-1)*(n-j)/2);
        i64 a = abs(ans);
        if (last != -1) {
            if (a < last) last = a;
        } else {
            last = a;
        }
        if (r - l == 1) break;
        if (ans > 0) r = j;
        else l = j;
    }
    std::cout << last << std::endl;
    
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