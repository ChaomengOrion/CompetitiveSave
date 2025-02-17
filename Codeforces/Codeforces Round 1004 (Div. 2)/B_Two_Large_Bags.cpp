#include <bits/stdc++.h>

using i64 = long long;

// a a
// a a a a+1
// a a a a a+1 a+2 -> a a+1 a+1 a+1 a+2 | a
// a a a+1 a+1 a+1 a+2
// a a a a+1 a+1 a+2
void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    int last = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= last) arr[i] = last + 1;
        if (i % 2 == 0) continue;
        if (arr[i - 1] == arr[i]) {
            last = arr[i];
        } else {
            std::cout << "No" << '\n';
            return;
        }
    }
    std::cout << "Yes" << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}