#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::string S;
    std::cin >> N >> S;
    i64 ans = 1LL * N * (N + 1) / 2;
    int need = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '1' && need + 1 <= i) { // 即使拿了，即need变成need+1，前面也有i个能满足
            ans -= i + 1; // 这个免费
            need++; // 需要前面拿一个过来
        } else {
            need = std::max(0, need - 1); // 填补后面的需要
        }
    }
    std::cout << ans << "\n";
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}