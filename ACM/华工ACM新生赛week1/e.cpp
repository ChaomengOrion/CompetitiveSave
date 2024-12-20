#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::string S;
    std::cin >> S;
    std::multiset<char, std::greater<>> set;
    for (int i = 0; i < N; i++) {
        set.insert(S[i]);
    }
    std::vector<char> newS(N, 0);
    while (M--) {
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        for (int i = l; i <= r; i++) {
            if (set.empty()) break;
            if (newS[i] == 0) {
                newS[i] = *set.begin();
                set.erase(set.begin());
            }
        }
        if (set.empty()) break;
    }
    for (auto str : newS) {
        std::cout << str;   
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}