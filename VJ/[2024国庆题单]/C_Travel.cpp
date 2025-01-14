#include <bits/stdc++.h>
// #define CFMode

using i64 = long long;

#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector map(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> map[i][j];
        }
    }

    std::vector<int> indexs(n - 1);
    for (int i = 1; i < n; i++) {
        indexs[i - 1] = i;
    }

    int cnt = 0;
    do {
        //DEBUGV(indexs, n - 1)
        int sum = map[0][indexs[0]]; 
        for (int i = 0; i < n - 2; i++) {
            sum += map[indexs[i]][indexs[i + 1]];
        }
        sum += map[indexs[n - 2]][0];
        if (sum == k) cnt++;
    } while(next_permutation(indexs.begin(), indexs.end()));

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