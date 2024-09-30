#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::vector<int> l(n, n), r(n, -1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        l[a[i]] = std::min(l[a[i]], i);
        r[a[i]] = std::max(r[a[i]], i);
    }
    int L = n, R = -1;
    std::vector<int> f(n);
    for (int i = 0; i < n; i++) {
        L = std::min(L, l[i]);
        R = std::max(R, r[i]);
        // DEBUG(L << '|' << R << ", i: " << i)
        if (R - L <= i) {
            int l = std::max(0, R - i);
            int r = std::min(n - 1, L + i); // 计算可到达的区间
            f[l]++;
            if (r < n - 1) {
                f[r + 1]--;
            }
        }
        //auto d = f;
        //for (int i = 1; i < n; i++) d[i] += d[i - 1];
        //DEBUGV(d, n)
    }
    
    for (int i = 1; i < n; i++) {
        f[i] += f[i - 1];
    }
    
    int ans = std::count(f.begin(), f.end(), n);
    std::cout << ans << "\n";
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