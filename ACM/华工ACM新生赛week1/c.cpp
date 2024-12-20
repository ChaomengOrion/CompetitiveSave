#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <string>
#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::string min = "";
    for (int i = 0; i < N; i++) {
        std::string temp;
        std::cin >> temp;
        if (min == "") min = temp;
        else {
            if (temp.size() < min.size()) min = temp;
            else if (temp.size() == min.size()) {
                min = std::min(min, temp);
            }
        }
    }
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        std::string temp;
        std::cin >> temp >> temp >> temp;
        if (temp.size() < min.size()) min = temp;
        else if (temp.size() == min.size()) {
            min = std::min(min, temp);
        }
    }
    std::cout << min << std::endl;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}