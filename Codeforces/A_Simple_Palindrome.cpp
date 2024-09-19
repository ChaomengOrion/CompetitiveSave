#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

static const char table[] = {'a', 'e', 'i', 'o', 'u'};

void solve()
{
    int n;
    std::cin >> n;
    int cnt = n / 5;
    int extra = n % 5;
    std::string ans;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < cnt; j++) {
            ans += table[i];
        }
        if (extra > 0) {
            ans += table[i];
            extra--;
        }
    }
    std::cout << ans << std::endl;
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