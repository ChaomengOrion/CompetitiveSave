#include <bits/stdc++.h>

void solve() {
    int N, K;
    std::cin >> N >> K; N--;
    for (int i = 0; i <= N; i++) {
        std::cout << ((i & N) == i ? K : 0) << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}