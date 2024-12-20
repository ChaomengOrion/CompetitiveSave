#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::deque<int> dq;
    std::multiset<int> add;
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.back() > arr[i]) {
            add.insert(dq.back() + 1);
            dq.pop_back();
        }
        dq.push_back(arr[i]);
    }
    int min;
    if (!add.empty()) min = *add.begin();
    else min = INT_MAX;
    for (int v : dq) {
        if (v <= min) std::cout << v << ' ';
        else add.insert(v + 1);
    }
    for (int v : add) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}
