#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;
//a(n+1) = 6*a(n) - a(n-1) + 2

std::vector<int> a(11);

void pre() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < a.size(); i++) {
        a[i] = 6 * a[i - 1] - a[i - 2] + 2;
    }
}

void solve() {
    int N;
    std::cin >> N;
    auto check = [&](int x) -> bool {
        auto it = std::lower_bound(a.begin(), a.end(), x);
        return it != a.end() && *it == x;
    };
    if (check(N)) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<int> ans(N);
    std::iota(ans.begin(), ans.end(), 1);
    for (int i = 0; i < N; i++) {
        if (check(i + 1)) std::swap(ans[i], ans[i + 1]);
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    pre();
    LOG(a);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}