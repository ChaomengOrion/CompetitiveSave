#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) std::cin >> arr[i];
    
    std::vector<int> fa(N);
    for (int i = 0; i < N; i++) fa[i] = i;
    auto find = [&](auto&& find, int x) -> int {
        return fa[x] == x ? x : fa[x] = find(find, fa[x]);
    };

    std::stack<int> q;
    for (int i = 0; i < N; i++) {
        int maxi = i;
        while (!q.empty() && arr[q.top()] > arr[i]) {
            if (maxi == i) maxi = fa[i] = q.top();
            else fa[q.top()] = maxi;
            q.pop();
        }
        q.push(maxi);
    }

    for (int i = 0; i < N; i++) std::cout << arr[find(find, i)] << ' ';
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}