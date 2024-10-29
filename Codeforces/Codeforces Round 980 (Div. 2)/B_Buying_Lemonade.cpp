#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    i64 N, K;
    std::cin >> N >> K;
    std::map<i64, int> cnt_map;
    for (int i = 0; i < N; i++) {
        i64 temp;
        std::cin >> temp;
        cnt_map[temp]++;
    }
    i64 rest = N, cur = 0, op = 0, zero = 0, index = 0;
    for (auto [num, cnt] : cnt_map) {
        cur += rest * (num - index);
        op += rest * (num - index);
        rest -= cnt;
        zero = cnt;
        index = num;
        //LOG(cur << ' ' << op)
        if (cur >= K) {
            std::cout << K + op - cur << std::endl;
            return;
        }
        op += zero;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}