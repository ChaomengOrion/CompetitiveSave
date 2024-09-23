// Tsinghua Bootcamp 2024 Day 4 M

#include <bits/stdc++.h>

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

// 题目要求：可以进行多次操作，在一次操作中，我们选择一个位置 i 并同时执行以下操作：a[i]=a[i]−1 和 a[i+1]=a[i+1]+1。找出 max(a1,a2,…,an)−min(a1,a2,…,an)的最小可能值。

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<std::array<i64, 2>> s;
    for (int i = 0; i < n; i++) {
        i64 v = a[i]; // 第i个数
        i64 c = 1;
        while (!s.empty()) {
            auto [x, y] = s.back();
            if (x / y < v / c) {
                break;
            }
            v += x;
            c += y;
            s.pop_back();
        }
        s.push_back({v, c});
    }

    auto [x, y] = s.back();
    i64 mx = (x + y - 1) / y;
    auto [u, v] = s[0];
    i64 mn = u / v;
    std::cout << mx - mn << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}