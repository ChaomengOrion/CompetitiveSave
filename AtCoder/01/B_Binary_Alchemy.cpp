#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    std::vector map(n, std::vector<int>());
    for (int i = 0; i < n; i++) {
        map[i].resize(i + 1, -1);
        for (int j = 0; j < i + 1; j++) {
            int a;
            std::cin >> a;
            map[i][j] = a;
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int b = i;
        //std::cout << "i: " << b << ", cur: " << cur << std::endl;
        if (b > cur) std::swap(b, cur);
        cur = map[cur][b] - 1;
    }

    std::cout << cur + 1 << std::endl;
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