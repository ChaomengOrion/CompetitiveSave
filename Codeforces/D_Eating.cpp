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

//如果我们吃了一个 msb 小于 x 的粘液，那么 x 的 msb 将永远不会减少，而如果我们吃了一个 msb 相等的粘液，那么 x 的 msb 将减少

void solve() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> arr(N), pre(N + 1);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] ^ arr[i - 1];
    }
    std::vector<std::array<int, 30>> map(N);
    for (int i = 0; i < N; i++) {
        int hbit = std::__lg(arr[i]);
        for (int j = 0; j <= hbit; j++) {
            map[i][j] = i;
        }
        for (int j = hbit + 1; j < 30; j++) {
            map[i][j] = i > 0 ? map[i - 1][j] : -1;
        }
    }
    LOG(map, map.size());
    while (Q--) {
        int x;
        std::cin >> x;
        LOGI("x", x);
        int pos = N;
        while (pos > 0) {
            if (x == 0) break;
            int hbit = std::__lg(x);
            int ind = map[pos - 1][hbit];
            if (ind == -1) {
                pos = 0;
                break;
            }
            x ^= pre[pos] ^ pre[ind + 1];
            LOGI("jmp", ind, x, arr[ind]);
            if (x < arr[ind]) {
                pos = ind + 1;
                break;
            }
            x ^= arr[ind];
            pos = ind;
            LOGI("eat", pos, x);
        }
        std::cout << N - pos << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}