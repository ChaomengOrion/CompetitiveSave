#include <bits/stdc++.h>
// #define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n, m; // n = number of vec, m = length of each vec
    std::cin >> n >> m;
    std::vector inputs(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> inputs[i][j];
        }
    }
    std::unordered_map<int, int> saved;
    std::vector<int> cnt(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        std::unordered_map<int, int> seen;
        for (int j = 0; j < m; j++) {
            int c = inputs[i][j];
            if (saved.contains(c)) {
                cnt[saved[c]]++;
            }
            else {
                seen.insert({c, i});
                cnt[i]++;
            }
        }
        for (auto a : seen) {
            saved.insert(a);
        }
    }

    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        sum += cnt[i];
    }
    std::cout << std::setprecision(9);
    for (int i = 0; i < n; i++) {
        std::cout << (double)cnt[i] / sum << std::endl;
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