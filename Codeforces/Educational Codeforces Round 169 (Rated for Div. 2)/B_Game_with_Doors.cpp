#include <bits/stdc++.h>
 
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
 
void solve() {
    unsigned l, r, L, R;
    std::cin >> l >> r >> L >> R;
    int count = 0;
    if (l == L) count--;
    if (r == R) count--;
    if (l > R || L > r) std::cout << "1\n";
    else if (l >= L && r <= R)
    {
        std::cout << r - l + 2 + count << '\n';
    }
    else if (L >= l && R <= r)
    {
        std::cout << R - L + 2 + count << '\n';
    }
    else if (l < L && r < R)
    {
        std::cout << r - L + 2 + count << '\n';
    }
    else if (L < l && R < r)
    {
        std::cout << R - l + 2 + count << '\n';
    }
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