#include <bits/stdc++.h>
// #define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, C;
    std::cin >> N >> C;
    std::vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());
    int k = 1;
    while (true) {
        int last = vec[0];
        int cnt = C - 1;
        for (int i = 1; i < N; i++) {
            if (vec[i] - last >= k) {
                last = vec[i];
                if (--cnt == 0) break;
            }
        }
        if (cnt > 0) break;; 
        k++;
    }
    std::cout << --k << std::endl;
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