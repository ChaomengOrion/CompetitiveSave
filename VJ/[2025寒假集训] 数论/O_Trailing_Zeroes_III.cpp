#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

/* 对于k！，其中至少包含一个p因子的数有k/p个
    两个p因子的有k/p^2个,
    但其中的一个上一步中已经计算,所以只要加上k/p^2即可*/

//* 二分答案
int check(int x)
{
    int s = 0;
    while (x) {
        s += x / 5;
        x /= 5;
    }
    return s;
}

void solve()
{
    static int cnt = 0;
    int n;
    std::cin >> n;
    int l = 1, r = n * 5, k, mid;
    int last = -1;
    if (n == 0) last = 1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        k = check(mid);
        if (k == n) {
            last = mid;
            r = mid - 1;
        } else if (k > n)
            r = mid - 1;
        else if (k < n)
            l = mid + 1;
    }
    if (last != -1)
        std::cout << "Case " << ++cnt << ": " << last << std::endl;
    else
        std::cout << "Case " << ++cnt << ": impossible" << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}