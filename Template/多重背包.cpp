#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> items; // weight, value

    // 二进制拆分每种物品的数量
    for (int i = 1; i <= N; i++) {
        int V, W, m;
        std::cin >> V >> W >> m;
        int k = 1;
        while(m > 0){
            int cnt = std::min(k, m);
            items.emplace_back(W * cnt, V * cnt);
            m -= cnt;
            k <<= 1;
        }
    }

    std::vector<int> dp(M + 1, 0);

    // 0-1 背包标准遍历
    for(auto &[weight, value] : items){
        for(int j = M; j >= weight; j--){
            dp[j] = std::max(dp[j], dp[j - weight] + value);
        }
    }

    std::cout << dp[M] << std::endl;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}