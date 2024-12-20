#include <bits/stdc++.h>

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(M);
    for (int i = 0; i < M; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end(), std::greater<>());

    std::vector<int> maxUse(N + 1, 0);
    std::vector<int> ans(N + 1);
    for (int i = 1; i <= N; i++) {
        int t = maxUse[i];
        ans[i] = arr[t++];
        if (2 * i <= N && t >= M) return void(std::cout << -1 << std::endl); 
        for (int p = 2 * i; p <= N; p += i) maxUse[p] = t;
    }

    for (int i = 1; i <= N; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}