#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    i64 cur = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            cur += a[i];
        }
        if (a[i] == 0 && cur > 0) {
            cur--;
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
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