#include <bits/stdc++.h>

int main()
{
    int T, n, x, a, maxn;
    std::cin >> T;
    while (T--) {
        maxn = 0;
        std::cin >> n >> x;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            std::cin >> a;
            if (a == x) {
                flag = 1;
            }
            maxn = std::max(maxn, a);
        }
        if (flag == 1) {
            std::cout << 1 << std::endl;
        } else if (maxn > x) {
            std::cout << 2 << std::endl;
        } else {
            std::cout << (int)ceil(x / (maxn * 1.0)) << std::endl;
        }
    }
    return 0;
}