#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> graph(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> graph[i];
    }
    std::vector<i64> pre(N + 1);
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] + graph[i];
    }

    i64 minCost = LONG_LONG_MAX;
    for (int start = 1; start <= N; start++) {
        i64 cost = graph[start] * (N - 1);
        cost += pre[start - 1] - pre[0] + pre[N] - pre[start];
        minCost = std::min(minCost, cost);
    }
    std::cout << minCost << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}