#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;
    if (N < 5) {
        std::cout << -1 << std::endl;
        return;
    }
    for (int i = 6; i <= N; i += 2) {
        std::cout << i << ' ';
    }
    std::cout << "2 4 5 1 3 ";
    for (int i = 7; i <= N; i += 2) {
        std::cout << i << ' ';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}