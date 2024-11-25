#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    std::string S;
    std::cin >> S;
    int cntC = 0, cntP = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'C') cntC++;
        if (S[i] == 'P') cntP++;
    }
    // CCPC CPC CPC CPC
    int ans = 0;
    if (cntP >= 1 && cntC >= 3) {
        ans++;
        cntP -= 1;
        cntC -= 3;
        ans += std::min(cntC / 2, cntP);
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}