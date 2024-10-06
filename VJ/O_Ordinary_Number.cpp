#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    bool pre = arr[1] > arr[0];
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        bool cur = arr[i] > arr[i - 1];
        if (pre == cur) cnt++;
        pre = cur;
    }
    std::cout << cnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}