#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> r1(N), r2(N);
    for (int i = 0; i < N; i++) std::cin >> r1[i];
    for (int i = 0; i < N; i++) std::cin >> r2[i];
    i64 sum = 0;
    int rest = INT_MIN;
    for (int i = 0; i < N; i++) {
        sum += std::max(r1[i], r2[i]);
        rest = std::max(rest, std::min(r1[i], r2[i]));
    }
    std::cout << sum + rest << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}