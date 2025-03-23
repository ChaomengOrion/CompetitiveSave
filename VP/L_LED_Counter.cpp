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

std::string num[10] = {
    "GGGgGGG",
    "gggggGG",
    "gGGGGGg",
    "ggGGGGG",
    "GggGgGG",
    "GgGGGgG",
    "GGGGGgG",
    "ggGggGG",
    "GGGGGGG",
    "GgGGGGG"
};

bool try_fit(const std::string& s, int x) {
    for (int i = 0; i < 7; i++) {
        if (s[i] == '+' || s[i] == '-') {
            continue;
        }
        if (s[i] != num[x][i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int N;
    std::cin >> N;
    std::vector<std::string> nums(N);
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }
    std::string ans;
    for (int i = 0; i < N; i++) {
        std::vector<int> fited;
        for (int d = 0; d <= 9; d++) {
            if (try_fit(nums[i], d)) {
                fited.emplace_back(d);
            }
        }
        if (fited.size() != 1) {
            ans += '*';
        } else {
            ans += '0' + (char)fited[0];
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}