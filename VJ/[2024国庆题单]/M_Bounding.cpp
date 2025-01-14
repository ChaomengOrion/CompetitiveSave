#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, X;
    std::cin >> N >> X;
    std::vector<int> L(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        std::cin >> L[i];
    }
    int pos = 0;
    for (int i = 0; i <= N; i++) {
        pos += L[i];
        if (pos > X) {
            std::cout << i << std::endl;
            return;
        }
    }
    std::cout << N + 1 << std::endl;
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