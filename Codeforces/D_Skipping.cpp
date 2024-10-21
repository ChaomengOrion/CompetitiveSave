#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> score(N + 1);
    std::vector<int> to(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> score[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> to[i];
    }

    std::set<int> unvis;
    for (int i = 1; i <= N; i++) {
        unvis.emplace_hint(unvis.end(), i);
    }
    
    i64 maxScore = 0;

    auto dfs = [&](auto&& dfs, int node, i64 pre_socre) {
        auto nit = unvis.upper_bound(node); // 取自己/前点
        if (nit == unvis.begin()) {
            maxScore = std::max(maxScore, pre_socre);
            return;
        }
        auto it = std::prev(nit);
        node = *it;
        i64 cur = pre_socre + score[node];
        // 取点
        unvis.erase(node);
        dfs(dfs, node - 1, cur); // 向前找
        unvis.emplace_hint(nit, node);
        if (to[node] > node) { // 大于自己才考虑跳点
            unvis.erase(node);
            dfs(dfs, to[node], pre_socre); // 跳点
            unvis.emplace_hint(nit, node);
        }
    };

    dfs(dfs, 1, 0);

    std::cout << maxScore << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}