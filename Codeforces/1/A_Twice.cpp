#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;
    std::map<int, int> map;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        map[temp]++;
    }
    int sc = 0;
    for (auto [k, v] : map) {
        sc += v / 2;
    }
    std::cout << sc << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}