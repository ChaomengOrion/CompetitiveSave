#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    if (S.find('p') == S.npos || S.find('s') == S.npos) {
        std::cout << "YES" << std::endl;
        return;
    }
    if (S.find_first_of('p') < S.find_last_of('s')) {
        std::cout << "NO" << std::endl;
        return;
    }
    char flag = 0;
    for (int i = 1; i < N - 1; i++) {
        if (flag == 0 && S[i] != '.') {
            flag = S[i];
        }
        if (flag != 0 && S[i] != '.') {
            if (S[i] != flag) {
                std::cout << "NO" << std::endl;
                return;
            }
        }
    }
    std::cout << "YES" << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}