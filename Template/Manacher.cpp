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

int manacher(const std::string& s) {
    std::string S = "^#";
    for (int i = 0; i < (int)s.size(); i++) {
        S += s[i];
        S += "#";
    }
    S += '$';
    int N = S.size();
    std::vector<int> p(N);
    int c = 0, r = 0; // 翼展最右的蘑菇中心/右边界
    for (int i = 2; i < N - 2; i++) {
        if (i <= r) p[i] = std::min(r - i, p[2 * c - i]); // 碰到前面蘑菇的边界 or 完全复制前面的
        while (S[i - p[i] - 1] == S[i + p[i] + 1]) p[i]++;
        if (i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
    }
    return *std::max_element(p.begin(), p.end());
}

int manacher2(const std::string& s) {
    std::string S = "^";
    S += s;
    S += '$';
    int N = S.size();
    std::vector<int> p(N);
    int c = 0, r = 0; // 翼展最右的蘑菇中心/右边界
    for (int i = 1; i < N - 1; i++) {
        if (i <= r) p[i] = std::min(r - i, p[2 * c - i]); // 碰到前面蘑菇的边界 or 完全复制前面的
        while (S[i - p[i] - 1] == S[i + p[i] + 1]) p[i]++;
        if (i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
    }
    int ans_mid = *std::max_element(p.begin(), p.end()) * 2 + 1;
    
    std::fill(p.begin(), p.end(), 0);
    c = 0, r = 0; // 翼展最右的蘑菇中心/右边界
    for (int i = 1; i < N - 2; i++) {
        if (i <= r) p[i] = std::min(r - i, p[2 * c - i]); // 碰到前面蘑菇的边界 or 完全复制前面的
        while (S[i - p[i]] == S[i + p[i] + 1]) p[i]++;
        if (i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
    }
    int ans_sub = *std::max_element(p.begin(), p.end()) * 2;

    return std::max(ans_mid, ans_sub);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string S;
    std::cin >> S;
    std::cout << manacher2(S) << '\n';
}