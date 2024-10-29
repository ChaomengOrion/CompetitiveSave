#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<i64> pre(N + 1);
    for (int i = 1; i <= N; i++) {
        int temp;
        std::cin >> temp;
        pre[i] = temp + pre[i - 1];
    }
    std::set<i64> store;
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        i64 cur = pre[i];
        if (store.find(cur) != store.end()) {
            cnt++;
            store.clear();
        }
        store.emplace(cur);
    }
    std::cout << cnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}