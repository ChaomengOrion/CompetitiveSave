#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

constexpr i64 inf = 1E18;

void solve() {
    int n;
    std::cin >> n;
    // 当前点的价值
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    // 当前点的跳点
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i]--;
    }
    
    std::vector<i64> dp(n, inf); // dp[i] 从起点出发到达i处的最小浪费点数
    
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> q;
    q.emplace(0LL, 0);
    
    while (!q.empty()) {
        // d是浪费的点数，i是点的位置
        auto [d, i] = q.top();
        q.pop();
        if (dp[i] != inf) {
            LOG(i + 1 << " has been checked")
            continue;
        }
        LOG(i + 1 << " minWaste = " << d)
        dp[i] = d;
        
        LOG("jump push " << b[i] + 1)
        q.emplace(d + a[i], b[i]);
        if (i > 0) {
            LOG("fetch push " << i)
            q.emplace(d, i - 1);
        }
    }
    
    i64 ans = 0;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = std::max(ans, sum - dp[i]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}