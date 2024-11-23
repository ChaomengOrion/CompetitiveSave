#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::pair<int, int>> ranges(N);
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < N; i++) {
        std::cin >> ranges[i].first >> ranges[i].second;
        min = std::min(min, ranges[i].first);
        max = std::max(max, ranges[i].second);
    }
    std::sort(ranges.begin(), ranges.end());
    int M = std::max(N - K, 2);

    auto check = [&](int mid) -> bool {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < N; i++) {
            if (ranges[i].second - ranges[i].first < mid) continue;
            pq.emplace(ranges[i].second);
            int r = ranges[i].first + mid;
            while (!pq.empty() && pq.top() < r) {
                pq.pop();
            }
            if (pq.size() >= M) return true;
        }
        return false;
    };

    int l = 0, r = max - min;
    
    while (l < r) {
        int mid = (0LL + l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << l << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}