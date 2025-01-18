#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::vector<std::vector<int>> vals(N, std::vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> vals[i][j];
        }
        std::sort(vals[i].begin(), vals[i].end());
    }

    while(Q--) {
        int a, b, c, d, K;
        std::cin >> a >> b >> c >> d >> K;
        a--; b--; c--; d--;
        int l = -1e8 - 3, r = 1e8 + 3;
        while (l < r) {
            int mid = (l + r) >> 1;
            auto ai = std::upper_bound(vals[a].begin(), vals[a].end(), mid);
            auto bi = std::upper_bound(vals[b].begin(), vals[b].end(), mid);
            auto ci = std::upper_bound(vals[c].begin(), vals[c].end(), mid);
            auto di = std::upper_bound(vals[d].begin(), vals[d].end(), mid);
            int av = ai - vals[a].begin();
            int bv = bi - vals[b].begin();
            int cv = ci - vals[c].begin();
            int dv = di - vals[d].begin();
            int index = av + bv + cv + dv;
            if (index > K) {
                r = mid - 1;
            } else if (index < K) {
                l = mid + 1;
            } else {

                int ans = INT_MIN;
                if (ai != vals[a].begin()) ans = std::max(ans, *prev(ai));
                if (bi != vals[b].begin()) ans = std::max(ans, *prev(bi));
                if (ci != vals[c].begin()) ans = std::max(ans, *prev(ci));
                if (di != vals[d].begin()) ans = std::max(ans, *prev(di));
                l = r = ans;
                break;
            }
        }
        std::cout << l << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}