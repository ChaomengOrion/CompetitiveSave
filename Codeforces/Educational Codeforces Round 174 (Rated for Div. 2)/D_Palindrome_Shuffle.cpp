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
    int l = -1, r = -1;
    for (int i = 0; i < N / 2; i++) {
        if (S[i] != S[N - 1 - i]) {
            if (l == -1) {
                l = r = i;
            } else {
                r = i;
            }
        }
    }
    if (l == -1) {
        std::cout << 0 << '\n';
        return;
    }
    int M = N / 2 - l;
    std::string A = S.substr(l, N / 2 - l),
                B = S.substr(N / 2, N / 2 - l);
    LOG(A, B);
    std::map<char, int> cntA, cntB;
    for (int i = 0; i < M; i++) {
        cntA[A[i]]++;
        cntB[B[i]]++;
    }
    std::map<char, int> overA, overB;
    for (auto [k, v] : cntA) {
        if (v > cntB[k]) {
            overA[k] = (v - cntB[k]) / 2; //* 多了多少
        }
    }
    for (auto [k, v] : cntB) {
        if (v > cntA[k]) {
            overB[k] = (v - cntA[k]) / 2; //* 多了多少
        }
    }
    if (overA.empty() && overB.empty()) {
        std::cout << r - l + 1 << '\n';
        return;
    }
    int costA = 0, costB = 0;
    LOG(overA.size(),overB.size());
    for (int i = 0; i < M; i++) {
        if (overB.size() == 0) break;
        if (overB.contains(B[i]) && overB[B[i]] > 0) {
            overB[B[i]]--;
            if (overB[B[i]] == 0) {
                overB.erase(B[i]);
            }
        }
        costB++;
    }
    for (int i = M - 1; i >= 0; i--) {
        if (overA.size() == 0) break;
        if (overA.contains(A[i]) && overA[A[i]] > 0) {
            overA[A[i]]--;
            if (overA[A[i]] == 0) {
                overA.erase(A[i]);
            }
        }
        costA++;
    }
    LOG(costA, costB);
    std::cout << std::min(costA, costB) + M << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}