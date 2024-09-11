#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    
    int mul = 1;
    std::vector<int> ans;
    auto handle = [&](auto handle, int n) -> void
    {
        if (n < 4) {
            std::cout << n << ' ';
            mul *= n;
            return;
        }
        int a = n / 2, b = n - a;
        handle(handle, a);
        handle(handle, b);
    };

    handle(handle, n);
    std::cout << '\n' << mul << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}