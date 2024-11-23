#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    int max = 0;
    int l = -1, r = -1, m = -1;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            if (l == -1) l = i;
            if (m != -1) {
                l = i;
                m = -1;
                r = -1;
            }
        }
        if (S[i] == '/') {
            max = std::max(1, max);
            if (l != -1 && m == -1) {
                m = i;
            } else {
                l = r = m = -1;
            }
        }
        if (S[i] == '2') {
            if (m != -1) {
                r = i;
                int cur = std::min(m - l, r - m);
                max = std::max(max, cur * 2 + 1);
            } else {
                l = r = m = -1;
            }
        }
    }
    std::cout << max << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}