#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N, R;
    std::cin >> N >> R;
    std::vector<int> fams(N);
    for (int i = 0; i < N; i++) {
        std::cin >> fams[i];
    }
    int cnt = 0, rest = 0;
    for (int i = 0; i < N; i++) {
        if (fams[i] % 2 == 0) {
            cnt += fams[i];
        } else {
            cnt += fams[i] - 1;
            rest++;
        }
    }
    int rest_rows = R - cnt / 2;
    if (rest <= rest_rows) {
        cnt += rest;
    } else {
        cnt += 2 * rest_rows - rest;
    }
    std::cout << cnt << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}