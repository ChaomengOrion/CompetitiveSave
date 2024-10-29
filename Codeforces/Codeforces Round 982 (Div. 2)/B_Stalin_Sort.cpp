#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        pq.emplace(temp, i);
    }
    int min = INT_MAX;
    int cost = 0;
    while (!pq.empty()) {
        auto [v, d] = pq.top();
        min = std::min(min, d + cost);
        pq.pop();
        cost++;
    }
    std::cout << min << std::endl;
    
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}