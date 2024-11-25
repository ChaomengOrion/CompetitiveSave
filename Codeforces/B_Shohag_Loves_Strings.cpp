#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    std::string S;
    std::cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if (i - 1 >= 0 && S[i] == S[i - 1]) {
            std::cout << S.substr(i - 1, 2) << std::endl;
            return;
        }
        if (i - 2 >= 0 && S[i] != S[i - 1] && S[i - 1] != S[i - 2] && S[i] != S[i - 2]) {
            std::cout << S.substr(i - 2, 3) << std::endl;
            return;
        }
    }
    std::cout << -1 << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}