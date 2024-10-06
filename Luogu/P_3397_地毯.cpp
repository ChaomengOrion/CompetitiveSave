#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, M;
    std::cin >> N >> M;
    std::vector delta(N + 2, std::vector<int>(N + 2, 0));
    while (M--) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        delta[x1][y1]++;
        delta[x1][y2 + 1]--;
        delta[x2 + 1][y1]--;
        delta[x2 + 1][y2 + 1]++;
    }

#if 0
修改
###+@@@-
###@@@@#
###-###+
#endif

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            delta[i][j] += delta[i - 1][j] + delta[i][j - 1] - delta[i - 1][j - 1];
            std::cout << delta[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}