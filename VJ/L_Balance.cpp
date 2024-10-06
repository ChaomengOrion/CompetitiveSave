#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> weights(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
        sum += weights[i];
    }
    int front_sum = 0;
    int min = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        front_sum += weights[i];
        min = std::min(min, abs(2 * front_sum - sum));
    }
    std::cout << min << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}