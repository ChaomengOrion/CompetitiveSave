#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#    include "[debug]util.hpp"
#    define LOG(...) \
        std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#    define LOGI(info, ...)                                        \
        std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", \
            __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#    define LOGA(...)                           \
        std::cerr << "[" << __LINE__ << "]: [", \
            __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#    define LOG(...)
#    define LOGI(...)
#    define LOGA(...)
#endif

using i64 = long long;

bool test(int x, int& num4, int& num6) {
    num4 = x / 4;
    int rest = x % 4;
    while (true) {
        if (num4 == 0) {
            return false;
        }
        num4--;
        rest += 4;

        if (rest % 6 == 0) {
            num6 = rest / 6;
            break;
        }
    }
    return true;
}

void solve() {
    int N, M;
    std::cin >> N >> M;
    if (N * M % 4 != 0) {
        std::cout << "NO" << '\n';
        return;
    }
    std::vector ans(N, std::vector<int>(M));

    int n4, n6;

    if (N % 4 == 0) {
        int cnt = 4;
        for (int j = 0; j < M; j++) {
            for (int i = 0; i < N; i++) {
                ans[i][j] = cnt / 4;
                cnt++;
            }
        }
    } else if (M % 4 == 0) {
        int cnt = 4;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ans[i][j] = cnt / 4;
                cnt++;
            }
        }
    } else if (test(M, n4, n6)) {
        int cnt = 1;
        for (int i = 0; i < N; i += 2) {
            for (int j = 0; j < n6 * 6; j += 6) {
                ans[i][j] = cnt;
                ans[i][j + 1] = cnt;
                ans[i][j + 2] = cnt;
                ans[i + 1][j] = cnt++;

                ans[i][j + 3] = cnt;
                ans[i][j + 4] = cnt;
                ans[i][j + 5] = cnt;
                ans[i + 1][j + 5] = cnt++;

                ans[i + 1][j + 1] = cnt;
                ans[i + 1][j + 2] = cnt;
                ans[i + 1][j + 3] = cnt;
                ans[i + 1][j + 4] = cnt++;
            }
        }
        cnt *= 4;
        for (int i = 0; i < N; i++) {
            for (int j = n6 * 6; j < M; j++) {
                ans[i][j] = cnt / 4;
                cnt++;
            }
        }
    } else if (test(N, n4, n6)) {
        int cnt = 1;
        for (int i = 0; i < n6 * 6; i += 6) {
            for (int j = 0; j < M; j += 2) {
                ans[i][j] = cnt;
                ans[i + 1][j] = cnt;
                ans[i + 2][j] = cnt;
                ans[i][j + 1] = cnt++;

                ans[i + 3][j] = cnt;
                ans[i + 4][j] = cnt;
                ans[i + 5][j] = cnt;
                ans[i + 5][j + 1] = cnt++;

                ans[i + 1][j + 1] = cnt;
                ans[i + 2][j + 1] = cnt;
                ans[i + 3][j + 1] = cnt;
                ans[i + 4][j + 1] = cnt++;
            }
        }
        cnt *= 4;
        for (int j = 0; j < M; j++) {
            for (int i = n6 * 6; i < N; i++) {
                ans[i][j] = cnt / 4;
                cnt++;
            }
        }
    } else {
        std::cout << "NO" << '\n';
        return;
    }
    std::cout << "YES" << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}