#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::pair<int, int>> ranges(N);
    for (int i = 0; i < N; i++) {
        std::cin >> ranges[i].first >> ranges[i].second;
    }
    std::sort(ranges.begin(), ranges.end());
    int M = std::max(N - K, 2);

    auto check = [&](int mid) -> bool {
        //std::cout << mid << std::endl;
        std::deque<int> dq;
        int jmpcnt = 0;
        for (int i = 0; i < N; i++) {
            if (ranges[i].second - ranges[i].first < mid) {
                jmpcnt++;
                continue;
            }
            while (!dq.empty() && ranges[dq.back()].second > ranges[i].second) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i - jmpcnt + 1 >= M) {
                while (!dq.empty() && dq.front() <= i - M - jmpcnt) {
                    dq.pop_front();
                }
                //std::cout << i << ": " << ranges[i].first << " | " << ranges[dq.front()].second << " [back:] " << ranges[dq.back()].second << std::endl;
                if (ranges[dq.front()].second - ranges[i].first >= mid) {
                    //std::cout << "TR" << std::endl;
                    return true;
                }
            }
        }
        //std::cout << "FLASE" << std::endl;
        return false;
    };

    int l = 0, r = 1E9;
    
    while (l < r) {
        int mid = (l + r + 1) >> 1;
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