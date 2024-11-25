#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;
    int cnt = 0;
    std::string T = "";
    int l = -1, r = -1, e = S.size();
    for (int i = 0; i < S.size(); i++) {
        if (i == 0 && S[i] == '1') cnt++;
        else if (i > 0) {
            if (S[i - 1] == '0' && S[i] == '1') cnt++;
            if (S[i - 1] == '1' && S[i] == '0' && cnt == K - 1) {
                l = i;
            }
            if (S[i - 1] == '0' && S[i] == '1' && cnt == K) {
                r = i;
            }
            if (S[i - 1] == '1' && S[i] == '0' && cnt == K) {
                e = i;
            }
        }
    }
    std::string ans = S.substr(0, l) + S.substr(r, e - r) + S.substr(l, r - l) + S.substr(e);
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}