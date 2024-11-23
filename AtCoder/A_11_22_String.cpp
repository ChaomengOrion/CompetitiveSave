#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    if (N & 1 ^ 1) {
        std::cout << "No" << std::endl;
        return;
    }
    int pos = (N + 1) / 2 - 1;
    for (int i = 0; i < N; i++) {
        if (i < pos) {
            if (S[i] != '1') {
                std::cout << "No" << std::endl;
                return;
            }
        }
        if (i == pos) {
            if (S[i] != '/') {
                std::cout << "No" << std::endl;
                return;
            }
        }
        if (i > pos) {
            if (S[i] != '2') {
                std::cout << "No" << std::endl;
                return;
            }
        }
    }
    std::cout << "Yes" << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}