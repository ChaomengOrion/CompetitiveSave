#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int a, b;
    std::cin >> a >> b;
    int sum = a + b;
    if (sum & 1) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        std::cout << sum / 2 << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}