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

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;
    std::vector<int> score(N);
    for (int i = 0; i < N; i++) {
        std::cin >> score[i];
    }

    auto check = [&](int max) -> bool {
        std::vector<char> print(N);
        for (int i = 0; i < N; i++) {
            if (S[i] == 'B' && score[i] > max) {
                print[i] = 1;
            }
            if (S[i] == 'R' && score[i] > max) {
                print[i] = -1;
            }
        }
        char last = 0; int cost = 0;
        for (int i = 0; i < N; i++) {
            if (print[i] == 1 && last != 1) {
                cost++;
            }
            if (print[i] != 0) {
                last = print[i];
            }
        }
        LOG(max, cost);
        return cost <= K;
    };

    int l = 0, r = *std::max_element(score.begin(), score.end());
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}