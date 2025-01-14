#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const int P = 133;

void solve()
{
    int N;
    std::cin >> N;
    std::string A, B;
    std::cin >> A >> B;

    std::vector<i64> ans;

    for (int l = 0; l < N; l++) {
        int p = 0;
        i64 hash = 0;
        for (int r = l; r < N; r++, p++) {
            while (p < N && A[p] != B[r]) {
                p++;
            }
            if (p >= N) break;
            hash = hash * P + B[r];
            ans.emplace_back(hash);
        }
    }

    std::sort(ans.begin(), ans.end());

    std::cout << std::unique(ans.begin(), ans.end()) - ans.begin() << std::endl;
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