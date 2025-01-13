#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) //std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (int)(_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (int)(_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

struct node {
    i64 x;
    i64 val;
};

void solve() {
    i64 N, D, K;
    std::cin >> N >> D >> K;
    std::vector<node> girds(N);
    for (int i = 0; i < N; i++) {
        std::cin >> girds[i].x >> girds[i].val;
        girds[i].x--;
    }

    auto check = [&](int g) -> bool {
        if (D + g < girds[0].x) return false;
        std::vector<i64> f(N, LLONG_MIN);
        std::deque<int> dq;
        std::queue<int> pending;
        for (int i = 0; i < N; i++) {
            while (!pending.empty() && girds[pending.front()].x + D - g <= girds[i].x) {
                while (!dq.empty() && f[dq.back()] <= f[pending.front()]) {
                    dq.pop_back();
                }
                dq.push_back(pending.front());
                pending.pop();
            }
            while (!dq.empty() && girds[dq.front()].x + D + g < girds[i].x) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                f[i] = f[dq.front()] + girds[i].val;
                if (D - g <= girds[i].x + 1 && girds[i].x + 1 <= D + g) f[i] = std::max(f[i], girds[i].val);
            } else {
                if (D - g <= girds[i].x + 1 && girds[i].x + 1 <= D + g) f[i] = girds[i].val;
                else f[i] = LLONG_MIN;
            }
            if (f[i] != LLONG_MIN) pending.push(i);
            if (f[i] >= K) {
                LOGV(f, f.size())
                LOG("check g = " << g << ": success");
                return true;
            }
        }
        LOGV(f, f.size())
        LOG("check g = " << g << ": end but not enough");
        return false;
    };

    int l = 0, r = 5e5+7;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (r == 5e5+7) r = -1;

    std::cout << r << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}