#include <bits/stdc++.h>

int mex(int a, int b, int c) {
    int ans = 0;
    if (a > b) std::swap(a, b); 
    if (b > c) std::swap(b, c); 
    if (a > b) std::swap(a, b); 
    if (ans == a) ans++;
    if (ans == b) ans++;
    if (ans == c) ans++;
    return ans;
}

void solve() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    auto get = [&](int x) -> int {
        return (x + N - 1) % N + 1;
    };

    std::vector<int> ans(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        int c = -1;
        if (i == X) c = ans[Y];
        else if (i == Y) c = ans[X];
        ans[i] = mex(ans[get(i - 1)], ans[get(i + 1)], c);
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}