#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (sum % n > 0) {
        std::cout << "Draw" << std::endl;
        return;
    }
    i64 avg = sum / n, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > avg) {
            cnt += a[i] - avg;
        }
        if (abs(a[i] - avg) % k != 0) {
            std::cout << "Draw" << std::endl;
            return;
        }
    }
    std::cout << ((cnt / k & 1) ? 'F' : 'L')  << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}