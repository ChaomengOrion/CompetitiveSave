#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void solve()
{
    std::string S, T;
    std::cin >> S >> T;
    int len = S.length();
    std::vector<int> deltaP;
    std::vector<int> deltaN;
    deltaP.reserve(len);
    deltaN.reserve(len);

    for (int i = 0; i < len; i++) {
        int delta = T[i] - S[i];
        if (delta > 0) {
            deltaP.push_back(i);
        } else if (delta < 0) {
            deltaN.push_back(i);
        }
    }

    std::cout << deltaP.size() + deltaN.size() << std::endl;

    for (int i = 0; i < deltaN.size(); i++) {
        int pos = deltaN[i];
        S[pos] = T[pos];
        std::cout << S << std::endl;
    }

    for (int i = deltaP.size() - 1; i >= 0; i--) {
        int pos = deltaP[i];
        S[pos] = T[pos];
        std::cout << S << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}