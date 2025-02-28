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
    std::string S;
    std::cin >> S;
    int N = S.size();
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'A') {
            int j = i - 1;
            while (j >= 0 && S[j] == 'W') {
                S[j] = 'C';
                j--;
            }
            j++;
            if (i - j > 0) {
                S[i] = 'C';
                S[j] = 'A';
            }
        }
    }
    std::cout << S << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}