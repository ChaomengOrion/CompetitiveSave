#include <bits/stdc++.h>

void solve()
{
    int N;
    std::cin >> N;
    std::array<int, 3> dp = {}, dp_old = {};
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            int temp;
            std::cin >> temp;
            dp[j] = temp + std::max(dp_old[(j+1)%3], dp_old[(j+2)%3]);
        }
        std::swap(dp, dp_old);
    }
    std::cout << *std::max_element(dp_old.begin(), dp_old.end()) << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}