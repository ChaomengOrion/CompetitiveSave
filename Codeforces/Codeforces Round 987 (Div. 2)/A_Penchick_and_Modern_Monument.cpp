#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_operations_to_make_non_decreasing(vector<int>& h) {
    int n = h.size();
    vector<int> dp(n, 1);  // dp[i] 表示以 h[i] 结尾的最长非递减子序列的长度

    // 构建 dp 数组
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (h[i] >= h[j]) {  // 如果 h[i] >= h[j]，可以将 h[i] 加入到以 h[j] 结尾的非递减子序列
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 最长非递减子序列的长度
    int longest_non_decreasing = *max_element(dp.begin(), dp.end());

    // 最少需要修改的操作次数
    return n - longest_non_decreasing;
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    cout << min_operations_to_make_non_decreasing(h) << endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}