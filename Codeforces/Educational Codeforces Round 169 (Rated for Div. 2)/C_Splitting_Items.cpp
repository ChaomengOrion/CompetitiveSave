#include <bits/stdc++.h>

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
    std::sort(arr.rbegin(),arr.rend());

    int nPair = n / 2;
    
    i64 sum = 0;
    for (size_t i = 0; i < nPair; i++)
    {
        sum += arr[2 * i] - arr[2 * i + 1];
    }

    i64 res;

    if (sum >= k) res = sum - k;
    else res = 0;

    // 考虑余项
    if (n % 2) res += arr[n-1];
    std::cout << res << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}