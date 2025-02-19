#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    int cnt = 0;
    char last = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != last) {
            cnt++;
        }
        last = S[i];
    }
    if (S[0] == '0') cnt--;
    std::cout << std::max(0, cnt) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}