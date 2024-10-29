#include <bits/stdc++.h>

void solve()
{
    int N;
    std::cin >> N;
    std::vector map(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }
    int ans = 0;
    for (int d = - N + 1; d < N; d++) {
        int x = 0, y = d;
        y += std::max(0, -d);
        x += std::max(0, -d);
        int min = INT_MAX;
        while (y < N && x < N) {
            min = std::min(map[x][y], min);
            y++, x++;
        }
        if (min < 0) {
            ans += -min;
        }
    }
    std::cout << ans << std::endl;
    
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}