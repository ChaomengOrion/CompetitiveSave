#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int cur;
        std::cin >> cur;
        a.emplace(upper_bound(a.begin(), a.end(), cur), cur);
        if (i & 1 ^ 1) std::cout << a[i / 2] << std::endl;
    }

    return 0;
}