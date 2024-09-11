#include <bits/stdc++.h>
 
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
 
void solve() {
    int len;
    std::cin >> len;
    if (len > 2)
    {
        std::cout << "NO\n";
        return;
    }
    std::vector<i64> arr(len);
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> arr[i];
    }
    i64 a = arr[0];
    i64 b = arr[1];
    if (b-a > 2) std::cout << "YES\n";
    else std::cout << "NO\n";
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