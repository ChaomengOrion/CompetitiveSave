#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cerr << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cerr << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

i64 hash(std::string s) {
    const int P = 133;
    i64 ans = 0;
    for (char c : s) {
        ans = ans * P + c;
    }
    return ans;
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<i64> hashs(n);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        hashs[i] = hash(s);
        //DEBUGI(s, hashs[i])
    }
    int cnt = 1;
    std::sort(hashs.begin(), hashs.end());
    for (int i = 1; i < n; i++) {
        if (hashs[i] != hashs[i-1]) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
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