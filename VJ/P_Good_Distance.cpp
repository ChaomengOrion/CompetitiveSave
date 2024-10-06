#include <bits/stdc++.h>

void solve()
{
    int N, D;
    std::cin >> N >> D;
    std::vector points(N, std::vector<int>(D, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            std::cin >> points[i][j];
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}