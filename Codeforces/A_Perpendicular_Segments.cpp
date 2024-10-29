#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int X, Y, K;
    std::cin >> X >> Y >> K;
    int m = std::min(X, Y);
    int AX = m, AY = 0, BX = 0, BY = m;
    int CX = 0, CY = 0, DX = m, DY = m;
    std::cout << AX << ' ' << AY << ' ' << BX << ' ' << BY << ' ' << std::endl;
    std::cout << CX << ' ' << CY << ' ' << DX << ' ' << DY << ' ' << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}