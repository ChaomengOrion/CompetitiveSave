#include <bits/stdc++.h>

using i64 = long long;

i64 Combination(i64 n, i64 m){
    if (m > n / 2) m = n - m;
    i64 res = 1;
    for (i64 i = 1; i <= m; ++i){
        res = res * (n - m + i) / i;
    }
    return res;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int L;
    std::cin >> L;
    std::cout << Combination(L - 1, 11) << std::endl;
    return 0;
}