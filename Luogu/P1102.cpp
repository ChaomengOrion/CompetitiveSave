#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int n, c;
    std::cin >> n >> c;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());
    int i = 0, j = 1, k = 0;
    i64 count = 0;
    bool modified = true;
    while (i < n - 1) {
        j = std::max(j, i+1);
        if (j > k) {
            k = j;
            while (k + 1 < n && vec[k + 1] == vec[k]) k++;
        }
        int delta = vec[j] - vec[i];
        if (delta == c) count += k-j+1;
        if (delta >= c) i++;
        else if (k+1 < n) j = k+1;
        else break;
    }
    std::cout << count << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}