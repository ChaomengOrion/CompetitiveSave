#include <bits/stdc++.h>

void solve() {
    int N; std::cin >> N;    
    std::vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp; std::cin >> temp;
            if (temp == 1) cnt[i]++;
            else cnt[i] = 0;
        }
    }
    std::sort(cnt.begin(), cnt.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i] >= ans) ans++;
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}