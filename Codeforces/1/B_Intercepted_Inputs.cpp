#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    std::set<int> set;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        set.insert(arr[i]);
    }
    int len = N - 2;
    for (int i = 1; i <= sqrtl(len); i++) {
        if (len % i == 0) {
            int a = i;
            int b = len / i;
            if (set.contains(a) && set.contains(b)) {
                std::cout << a << ' ' << b << std::endl;
                return;
            }
        }
    }
    std::cout << -1 << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}